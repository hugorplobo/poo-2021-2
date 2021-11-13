#pragma once

#include <iostream>
#include <sstream>

class Kid {
    std::string name;
    int age;
    int debt;

public:
    Kid(std::string name, int age) {
        this->age = age;
        this->debt = 0;
        this->set_name(name);
    }

    std::string to_string() {
        std::stringstream output;
        output << name << ": " << std::to_string(this->age);
        return output.str();
    }

    void set_name(std::string name) {
        name[0] = std::toupper(name[0]);
        this->name = name;
    }

    void set_debt(int value) {
        this->debt = value;
    }

    std::string get_name() {
        return this->name;
    }

    int get_age() {
        return this->age;
    }

    int get_debt() {
        return this->debt;
    }
};