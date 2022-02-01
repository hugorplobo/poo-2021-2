#pragma once

#include <iostream>
#include <vector>
#include "account.hpp"

class Client {
public:
    Client() : client_id {""} {}
    Client(std::string client_id) : client_id {client_id} {}

    void addAccount(Account* account) {
        this->accounts.push_back(account);
    }

    std::vector<Account*> get_accounts() const {
        return this->accounts;
    }

    std::string get_client_id() const {
        return this->client_id;
    }

    void set_accounts(std::vector<Account*> accounts) {
        this->accounts = accounts;
    }

    void set_client_id(std::string client_id) {
        this->client_id = client_id;
    }

    friend std::ostream& operator<<(std::ostream& os, Client& client) {
        os << client.client_id << " [ ";

        for (auto account : client.accounts) {
            os << account->get_id() << " ";
        }

        os << "]";

        return os;
    }

private:
    std::vector<Account*> accounts;
    std::string client_id;
};