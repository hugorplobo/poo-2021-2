#pragma once

#include "../contato/contato.hpp"
#include <algorithm>
#include <map>

class Agenda {
public:
    Agenda() {}

    void add_contact(std::shared_ptr<Contact> contact) {
        if (!this->contacts.count(contact->get_name())) {
            this->contacts[contact->get_name()] = contact;
        }        
    }

    std::shared_ptr<Contact> get_contact(const std::string &name) const {
        if (this->contacts.count(name)) {
            return this->contacts.at(name);
        }

        return nullptr;
    }

    void rm_contact(const std::string &name) {
        if (this->contacts.count(name)) {
            this->contacts.erase(name);
        }
    }

    std::vector<std::shared_ptr<Contact>> search(const std::string& pattern) const {
        std::vector<std::shared_ptr<Contact>> result;

        for (const auto &contact : this->contacts) {
            if (contact.second->get_name().find(pattern) != std::string::npos) {
                result.push_back(contact.second);
            }
        }

        return result;
    }

    const std::map<std::string, std::shared_ptr<Contact>>& get_contacts() const {
        return this->contacts;
    }

    friend std::ostream& operator<<(std::ostream &os, const Agenda& agenda) {
        for (const auto &contact : agenda.contacts) {
            os << *contact.second << std::endl;
        }

        return os;
    }

private:
    std::map<std::string, std::shared_ptr<Contact>> contacts;
};