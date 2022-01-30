#include <sstream>
#include "../headers/paciente.hpp"

Paciente::Paciente(const std::string& sender, const std::string& diag) {
    this->sender = sender;
    this->diagnostico = diag;
}

void Paciente::add_medico(IMedico* medico) {
    bool is_medic_already = this->medicos.count(medico->get_id());
    bool is_class_already = false;

    for (auto& [nome, medic] : this->medicos) {
        if (medic->get_classe() == medico->get_classe()) {
            is_class_already = true;
        }
    }

    if (is_medic_already) {
        throw std::string("fail: esse medico ja atende esse paciente");
    } else if (is_class_already) {
        throw std::string("fail: um medico dessa especialidade ja atende esse paciente");
    } else {
        this->medicos[medico->get_id()] = medico;
    }
}

void Paciente::remover_medico(const std::string& nome) {
    if (this->medicos.count(nome)) {
        this->medicos.erase(nome);
        return;
    }

    throw std::string("fail: medico nao encontrado nesse paciente");
}

std::string Paciente::get_id() {
    return this->sender;
}

std::string Paciente::get_diagnostico() {
    return this->diagnostico;
}

std::map<std::string, IMedico*> Paciente::get_medicos() {
    return this->medicos;
}

std::ostream& operator<<(std::ostream& os, Paciente* paciente) {
    std::stringstream output;
    output << "Pac: " << paciente->sender << ":" << paciente->diagnostico;

    os << output.str() << std::string(30 - output.str().size(), ' ') << "Meds: [";
    for (auto& [nome, medico] : paciente->medicos) {
        os << nome << (nome == (--paciente->medicos.end())->second->get_id() ? "" : ", ");
    }
    os << "]";

    return os;
}