#include <sstream>
#include "../headers/medico.hpp"
#include "../headers/ipaciente.hpp"

Medico::Medico(const std::string& id, const std::string& classe) {
    this->sender = id;
    this->classe = classe;
}

void Medico::add_paciente(IPaciente* paciente) {
    if (!this->pacientes.count(paciente->get_id())) {
        this->pacientes[paciente->get_id()] = paciente;
        return;
    }

    throw std::string("fail: esse medico ja atende esse paciente");
}

void Medico::remover_paciente(const std::string& nome) {
    if (this->pacientes.count(nome)) {
        this->pacientes.erase(nome);
        return;
    }

    throw std::string("fail: esse medico nao atende esse paciente");
}

std::string Medico::get_classe() {
    return this->classe;
}

std::string Medico::get_id() {
    return this->sender;
}

std::map<std::string, IPaciente*> Medico::get_pacientes() {
    return this->pacientes;
}

std::ostream& operator<<(std::ostream& os, Medico* medico) {
    std::stringstream output;
    output << "Med: " << medico->sender << ":" << medico->classe;

    os << output.str() << std::string(30 - output.str().size(), ' ') << "Pacs: [";
    for (auto& [nome, paciente] : medico->pacientes) {
        os << nome << (nome == (--medico->pacientes.end())->second->get_id() ? "" : ", ");
    }
    os << "]";

    return os;
}