#include "../headers/hospital.hpp"

Hospital::Hospital() = default;

void Hospital::add_medico(const std::string& nome, const std::string& classe) {
    if (!this->medicos.count(nome)) {
        this->medicos[nome] = new Medico(nome, classe);
        return;
    }

    throw std::string("fail: um medico com esse nome ja existe");
}

void Hospital::add_paciente(const std::string& nome, const std::string& diag) {
    if (!this->pacientes.count(nome)) {
        this->pacientes[nome] = new Paciente(nome, diag);
        return;
    }

    throw std::string("fail: um paciente com esse nome ja existe");
}

void Hospital::remover_medico(const std::string& medico) {
    if (this->medicos.count(medico)) {
        for (auto& [nome, paciente] : this->pacientes) {
            if (paciente->get_medicos().count(medico)) {
                paciente->remover_medico(medico);
            }
        }

        delete this->medicos.find(medico)->second;
        this->medicos.erase(medico);
        return;
    }

    throw std::string("fail: medico nao encontrado");
}

void Hospital::remover_paciente(const std::string& paciente) {
    if (this->pacientes.count(paciente)) {
        for (auto& [nome, medico] : this->medicos) {
            if (medico->get_pacientes().count(paciente)) {
                medico->remover_paciente(paciente);
            }
        }

        delete this->pacientes.find(paciente)->second;
        this->pacientes.erase(paciente);
        return;
    }

    throw std::string("fail: paciente nao encontrado");
}

void Hospital::vincular(const std::string& medico, const std::string& paciente) {
    if (!this->medicos.count(medico)) {
        throw std::string("fail: medico nao encontrado");
    } else if (!this->pacientes.count(paciente)) {
        throw std::string("fail: paciente nao encontrado");
    }

    this->pacientes[paciente]->add_medico(this->medicos[medico]);
    this->medicos[medico]->add_paciente(this->pacientes[paciente]);
}

std::ostream& operator<<(std::ostream& os, Hospital& hospital) {
    std::cout << "chegou" << std::endl;
    for (auto& [nome, paciente] : hospital.pacientes) {
        os << static_cast<Paciente*>(paciente) << std::endl;
    }

    for (auto& [nome, medico] : hospital.medicos) {
        os << static_cast<Medico*>(medico) << std::endl;
    }

    return os;
}