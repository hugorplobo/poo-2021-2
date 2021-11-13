#pragma once

#include "cliente.hpp"
#include <vector>
#include <memory>
#include <sstream>

class Sala {
    std::vector<std::shared_ptr<Cliente>> cadeiras;

public:
    Sala(int capacidade) : cadeiras {capacidade, nullptr} {}

    void cancelar(std::string id) {
        for (size_t i = 0; i < cadeiras.size(); i++) {
            if (this->cadeiras[i] != nullptr && this->cadeiras[i]->get_id() == id) {
                this->cadeiras[i] = nullptr;
                break;
            }
        }
    }

    bool reservar(std::string id, std::string telefone, int cadeira) {
        if (this->cadeiras[cadeira] != nullptr || cadeira >= this->cadeiras.size()) {
            return false;
        }

        this->cadeiras[cadeira] = std::make_shared<Cliente>(id, telefone);
        return true;
    }

    std::string to_string() {
        std::stringstream output;
        output << "[ ";

        for (size_t i = 0; i < this->cadeiras.size(); i++) {
            if (this->cadeiras[i] == nullptr) {
                output << "- ";
            } else {
                output << this->cadeiras[i]->to_string() << " ";
            }
        }

        output << "]";
        return output.str();
    }

    std::vector<std::shared_ptr<Cliente>>& get_cadeiras() {
        return this->cadeiras;
    }
};