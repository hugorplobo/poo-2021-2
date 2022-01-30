#pragma once
#include "ipaciente.hpp"

class Paciente : public IPaciente {
public:
    Paciente(const std::string&, const std::string&);
    void add_medico(IMedico*) override;
    void remover_medico(const std::string&) override;
    std::string get_diagnostico() override;
    std::string get_id() override;
    std::map<std::string, IMedico*> get_medicos() override;
    friend std::ostream& operator<<(std::ostream&, Paciente*);

private:
    std::string diagnostico;
    std::map<std::string, IMedico*> medicos;
    std::string sender;
};