#pragma once
#include <iostream>
#include <map>
#include "imedico.hpp"

class IPaciente {
public:
    virtual void add_medico(IMedico*) = 0;
    virtual void remover_medico(const std::string&) = 0;
    virtual std::string get_diagnostico() = 0;
    virtual std::string get_id() = 0;
    virtual std::map<std::string, IMedico*> get_medicos() = 0;
};