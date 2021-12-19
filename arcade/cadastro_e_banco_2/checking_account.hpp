#pragma once

#include "account.hpp"

class CheckingAccount : public Account {
public:
    CheckingAccount() : Account() {
        this->type = "CC";
    }

    CheckingAccount(int id, std::string client_id) : Account(id, client_id) {
        this->type = "CC";
    }

    void monthly_update() override {
        std::cout << "Valor: R$ " << 20 << " pago em taxas" << std::endl;
        this->balance -= 20;
    }
};