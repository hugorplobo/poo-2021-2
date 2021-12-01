#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include "pessoa.hpp"

class Motoca {
    Pessoa *pessoa {nullptr};
    int potencia {1};
    int tempo {0};

public:
    Motoca(int potencia) :
    potencia {potencia} {}

    ~Motoca() {
        delete this->pessoa;
    }

    void comprarTempo(int tempoComprado) {
        tempo += std::max(0, tempoComprado);
    }

    bool subir(Pessoa *novaPessoa) {
        if (novaPessoa != nullptr) {
            pessoa = novaPessoa;
            return true;
        }

        return false;
    }

    Pessoa* descer() {
        return std::exchange(pessoa, nullptr);
    }

    void buzinar() {
        std::cout << "P";
        for (int i = 0; i < potencia; i++) std::cout << "e";
        std::cout << "m\n";
    }

    void dirigir(int minutos) {
        if (pessoa != nullptr && pessoa->idade <= 10 && tempo > 0) {
            tempo -= minutos;

            if (tempo < 0) {
                tempo = 0;
                std::cout << "O seu tempo acabou!\n";
            }
        }
    }

    std::string toString() {
        std::stringstream str;
        str << "Pessoa: " << pessoa->toString() << "\nPotencia: " << potencia << "\nTempo: " << tempo;
        return str.str();
    }

    Pessoa* get_pessoa() const {
        return this->pessoa;
    }
};