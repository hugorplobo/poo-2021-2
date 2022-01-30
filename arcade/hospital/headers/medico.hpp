#pragma once
#include "imedico.hpp"

class Medico : public IMedico {
public:
    Medico(const std::string&, const std::string&);
    void add_paciente(IPaciente*) override;
    void remover_paciente(const std::string&) override;
    std::string get_classe() override;
    std::string get_id() override;
    std::map<std::string, IPaciente*> get_pacientes() override;
    friend std::ostream& operator<<(std::ostream&, Medico*);

private:
    std::string classe;
    std::map<std::string, IPaciente*> pacientes;
    std::string sender;
};