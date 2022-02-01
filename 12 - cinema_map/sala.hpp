#pragma once

#include "../cinema/cliente.hpp"
#include <map>
#include <memory>
#include <sstream>

class Sala {
    std::map<int, std::shared_ptr<Cliente>> cadeiras;
    int qtd_cadeiras;

public:
    Sala(int capacidade) : qtd_cadeiras {capacidade} {}

    void cancelar(std::string id) {
        for (auto& cliente : this->cadeiras) {
            if (cliente.second != nullptr && cliente.second->get_id() == id) {
                this->cadeiras.erase(cliente.first);
            }
        }
    }

    bool reservar(std::string id, std::string telefone, int cadeira) {
        if (this->qtd_cadeiras > this->cadeiras.size()) {
            for (auto& cliente : this->cadeiras) {
                if (cliente.second != nullptr && cliente.second->get_id() == id) {
                    return false;
                }
            }

            if (this->cadeiras[cadeira] == nullptr) {
                return false;
            }

            this->cadeiras[cadeira] = std::make_shared<Cliente>(id, telefone);
            return true;
        }

        return false;
    }

    std::string to_string() {
        std::stringstream output;
        output << "[ ";

        for (auto& cliente : this->cadeiras) {
            if (cliente.second == nullptr) {
                output << "- ";
            } else {
                output << cliente.second->to_string() << " ";
            }
        }

        output << "]";
        return output.str();
    }

    const std::map<int, std::shared_ptr<Cliente>>& get_cadeiras() {
        return this->cadeiras;
    }
};