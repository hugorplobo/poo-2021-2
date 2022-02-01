#pragma once
#include <iostream>
#include <map>
#include "imedico.hpp"
#include "ipaciente.hpp"
#include "medico.hpp"
#include "paciente.hpp"

class Hospital {
public:
    Hospital();
    void add_medico(const std::string&, const std::string&);
    void add_paciente(const std::string&, const std::string&);
    void remover_medico(const std::string&);
    void remover_paciente(const std::string&);
    void vincular(const std::string&, const std::string&);
    friend std::ostream& operator<<(std::ostream&, Hospital&);

private:
    std::map<std::string, IMedico*> medicos;
    std::map<std::string, IPaciente*> pacientes;
};