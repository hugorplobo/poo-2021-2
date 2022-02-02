#pragma once

#include "grafite.hpp"
#include <memory>
#include <vector>

class Lapiseira {
public:
    Lapiseira(double calibre)
    : calibre {calibre} {}

    bool inserir(double calibre, std::string dureza, int tamanho) {
        if (calibre != this->calibre) {
            this->tambor.push_back(std::make_shared<Grafite>(calibre, dureza, tamanho));
            return true;
        }

        return false;
    }

    bool puxar() {
        if (this->bico != nullptr || this->tambor.size() == 0) {
            return false;
        }

        auto grafite = this->tambor[0];
        this->tambor.erase(this->tambor.begin());
        this->bico = grafite;
        return true;
    }

    std::shared_ptr<Grafite> remover() {
        return std::exchange(this->bico, nullptr);
    }

    void escrever() {
        if (this->bico == nullptr) {
            std::cout << "Sem grafite no bico" << std::endl;
            return;
        }

        if (this->bico->get_tamanho() <= 10) {
            std::cout << "Grafite muito pequeno" << std::endl;
            return;
        }

        int novo_tamanho = this->bico->desgaste_por_folha();

        if (novo_tamanho <= 10) {
            this->bico->set_tamanho(10);
            std::cout << "Texto incompleto" << std::endl;
        }
    }

private:
    std::shared_ptr<Grafite> bico;
    double calibre;
    std::vector<std::shared_ptr<Grafite>> tambor;
};