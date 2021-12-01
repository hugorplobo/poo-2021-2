#pragma once

#include "fone.hpp"
#include <vector>
#include <memory>

class Contact {
public:
    Contact(std::string name, const std::vector<std::shared_ptr<Fone>> &fones)
    : name {name}, fones {fones}, prefix {"-"} {}

    void add_fone(std::shared_ptr<Fone> fone) {
        this->fones.push_back(fone);
    }

    void rm_fone(int index) {
        this->fones.erase(this->fones.begin() + index);
    }

    const std::vector<std::shared_ptr<Fone>>& get_fones() const {
        return this->fones;
    }

    std::string get_name() const {
        return this->name;
    }

    void set_name(std::string name) {
        this->name = name;
    }

    friend std::ostream& operator<<(std::ostream &os, const Contact &contact) {
        os << contact.prefix << " " << contact.name;
        for (const auto& fone : contact.fones) {
            os << " [ " << *fone << " ]";
        }
        return os;
    }

protected:
    std::string prefix;

private:
    std::string name;
    std::vector<std::shared_ptr<Fone>> fones;
};