#pragma once

#include "../contato/contato.hpp"
#include <algorithm>

class Agenda {
public:
    Agenda() {}

    void add_contact(std::shared_ptr<Contact> contact) {
        auto found = std::find_if(this->contacts.begin(), this->contacts.end(), [&](auto &x) {return x->get_name() == contact->get_name();});
        if (found == this->contacts.end()) {
            this->contacts.push_back(contact);
        } else {
            for (const auto &fone : contact->get_fones()) {
                (*found)->add_fone(fone);
            }
        }

        std::sort(this->contacts.begin(), this->contacts.end(), [](auto &x, auto &y) {return x->get_name() < y->get_name();});
    }

    std::shared_ptr<Contact> get_contact(const std::string &name) const {
        auto found = std::find_if(this->contacts.begin(), this->contacts.end(), [&](auto &x) {return x->get_name() == name;});
        if (found != this->contacts.end()) {
            return *found;
        }

        return nullptr;
    }

    void rm_contact(const std::string &name) {
        auto found = std::find_if(this->contacts.begin(), this->contacts.end(), [&](auto &x) {return x->get_name() == name;});
        if (found != this->contacts.end()) {
            this->contacts.erase(found);
        }
    }

    std::vector<std::shared_ptr<Contact>> search(const std::string& pattern) const {
        std::vector<std::shared_ptr<Contact>> result;

        for (const auto &contact : this->contacts) {
            if (contact->get_name().find(pattern) != std::string::npos) {
                result.push_back(contact);
            }
        }

        return result;
    }

    const std::vector<std::shared_ptr<Contact>>& get_contacts() const {
        return this->contacts;
    }

    friend std::ostream& operator<<(std::ostream &os, const Agenda& agenda) {
        for (const auto &contact : agenda.contacts) {
            os << *contact << std::endl;
        }

        return os;
    }

private:
    std::vector<std::shared_ptr<Contact>> contacts;
};