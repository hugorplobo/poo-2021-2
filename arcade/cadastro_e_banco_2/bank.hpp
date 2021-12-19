#pragma once

#include <iostream>
#include <map>
#include "client.hpp"
#include "account.hpp"
#include "checking_account.hpp"
#include "savings_account.hpp"

class Bank {
public:
    Bank() : next_id {0} {}

    ~Bank() {
        for (auto account : this->accounts) {
            delete account.second;
        }
    }

    void addClient(std::string client_id) {
        Client new_client(client_id);
        CheckingAccount* new_checking = new CheckingAccount(this->next_id++, client_id);
        SavingsAccount* new_savings = new SavingsAccount(this->next_id++, client_id);

        new_client.addAccount(new_checking);
        new_client.addAccount(new_savings);

        this->clients[client_id] = new_client;
        this->accounts[new_checking->get_id()] = new_checking;
        this->accounts[new_savings->get_id()] = new_savings;
    }

    void deposit(int id, double value) {
        if (value > 0) {
            this->accounts[id]->deposit(value);
        }
    }

    void monthly_update() {
        for (auto account : this->accounts) {
            account.second->monthly_update();
        }
    }

    void transfer(int id_from, int id_to, double value) {
        if (value > 0) {
            this->accounts[id_from]->transfer(this->accounts[id_to], value);
        }
    }

    void withdraw(int id, double value) {
        if (value > 0) {
            this->accounts[id]->withdraw(value);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Bank& bank) {
        os << "Clients: \n";

        for (auto client : bank.clients) {
            os << "- " << client.second << "\n";
        }

        os << "Accounts: \n";

        for (auto account : bank.accounts) {
            os << *account.second << "\n";
        }

        return os;
    }

private:
    std::map<int, Account*> accounts;
    std::map<std::string, Client> clients;
    int next_id;
};