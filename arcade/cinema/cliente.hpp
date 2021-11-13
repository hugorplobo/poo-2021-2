#pragma once

#include <iostream>

class Cliente {
    std::string id;
    std::string telefone;

public:
    Cliente(std::string id, std::string telefone)
    : id {id}, telefone {telefone} {}

    std::string to_string() {
        return this->id + ":" + this->telefone;
    }

    std::string get_telefone() {
        return this->telefone;
    }

    std::string get_id() {
        return this->id;
    }

    void set_telefone(std::string telefone) {
        this->telefone = telefone;
    }

    void set_id(std::string id) {
        this->id = id;
    }
};