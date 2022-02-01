#pragma once

#include <iostream>
#include <sstream>

class Pessoa {
    std::string nome {};
    int idade {0};

public:
    Pessoa(std::string nome, int idade) :
    nome {nome}, idade {idade} {}

    std::string toString() {
        std::stringstream str;
        str << nome << ", " << idade << " anos";
        return str.str();
    }

    friend class Motoca;

};