#pragma once
#include <iostream>
#include <map>

class IPaciente;

class IMedico {
public:
    virtual void add_paciente(IPaciente*) = 0;
    virtual void remover_paciente(const std::string&) = 0;
    virtual std::string get_classe() = 0;
    virtual std::string get_id() = 0;
    virtual std::map<std::string, IPaciente*> get_pacientes() = 0;
};