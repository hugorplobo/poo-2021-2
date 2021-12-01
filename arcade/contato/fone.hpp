#pragma once

#include <stdexcept>
#include <sstream>

class Fone {
public:
    Fone(std::string id, std::string number) {
        if (!Fone::validate(number)) {
            throw std::invalid_argument("Invalid character in the provided number");
        }

        this->id = id;
        this->number = number;
    }

    std::string get_id() const {
        return this->id;
    }

    void set_id(std::string id) {
        this->id = id;
    }

    std::string get_number() const {
        return this->number;
    }

    void set_number(std::string number) {
        this->number = number;
    }

    friend std::ostream& operator<<(std::ostream &os, const Fone &fone) {
        os << fone.id << ":" << fone.number;
        return os;
    }

private:
    std::string id;
    std::string number;

    static bool validate(std::string number) {
        for (const auto &n : number) {
            if ((n != '(' && n != ')') && (n > '9' || n < '0')) {
                return false;
            }
        }

        return true;
    }
};