#pragma once

#include <iostream>
#include <sstream>

class Grafite {
public:
    Grafite(double calibre, std::string dureza, int tamanho)
    : calibre {calibre}, dureza {dureza}, tamanho {tamanho} {}

    int desgaste_por_folha() {
        if (this->dureza == "HB") {
            return 1;
        }
        
        this->tamanho -= int(this->dureza[0]) - 48;
        return this->tamanho;
    };

    std::string to_string() {
        std::stringstream output;
        output << "Calibre: " << this->calibre << "\nDureza: " << this->dureza << "Tamanho: " << this->tamanho;
        return output.str();
    }

    int get_tamanho() {
        return this->tamanho;
    }

    void set_tamanho(int tamanho) {
        this->tamanho = tamanho;
    }

private:
    double calibre;
    std::string dureza;
    int tamanho;
};