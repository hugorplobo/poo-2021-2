#pragma once

#include <iostream>

class Account {
public:
    Account(int id = 0, std::string client_id = "") :
    balance {0}, client_id {client_id}, id {id}, type {""}  {}

    virtual void monthly_update() = 0;

    void deposit(double value) {
        if (value > 0) {
            std::cout << "Valor: R$ " << value << " depositado" << std::endl;
            this->balance += value;
        }
    }

    void transfer(Account* other, double value) {
        std::cout << "Valor: R$ " << value << " tranferido" << std::endl;
        other->deposit(value);
    }

    void withdraw(double value) {
        if (value > 0) {
            std::cout << "Valor: R$ " << value << " sacado" << std::endl;
            this->balance -= value;
        }
    }

    double get_balance() const {
        return this->balance;
    }

    std::string get_client_id() const {
        return this->client_id;
    }

    int get_id() const {
        return this->id;
    }

    std::string get_type() const {
        return this->type;
    }

    friend std::ostream& operator<<(std::ostream& os, Account& account) {
        os << account.id << ":" << account.client_id << ":" << account.balance << ":" << account.type;
        return os;
    }

protected:
    double balance;
    std::string client_id;
    int id;
    std::string type;
};