#pragma once

#include "account.hpp"

class SavingsAccount : public Account {
public:
    SavingsAccount() : Account() {
        this->type = "CP";
    }

    SavingsAccount(int id, std::string client_id) : Account(id, client_id) {
        this->type = "CP";
    }

    void monthly_update() override {
        std::cout << "Valor: R$ " << this->balance / 100 << " ganho ao fim do mês" << std::endl;
        this->balance += this->balance / 100;
    }
};