#pragma once

#include <iostream>
#include <sstream>
#include <list>
#include <memory>
#include "kid.hpp"

class Trampoline {
    std::list<std::shared_ptr<Kid>> playing;
    std::list<std::shared_ptr<Kid>> waiting;
    int money;

    std::list<std::shared_ptr<Kid>>::iterator find_kid(std::string name, std::list<std::shared_ptr<Kid>>& list) {
        name[0] = std::toupper(name[0]);
        for (auto it = list.begin(); it != list.end(); it++) {
            if ((*it)->get_name() == name) {
                return it;
            }
        }

        return list.end();
    }

    std::shared_ptr<Kid> remove_kid(std::list<std::shared_ptr<Kid>>::iterator kid, std::list<std::shared_ptr<Kid>>& list) {
        this->money += (*kid)->get_debt();
        (*kid)->set_debt(0);
        auto output = *kid;
        list.erase(kid);
        return output;
    }

public:
    Trampoline() {
        this->money = 0;
    }

    void arrive(std::shared_ptr<Kid> kid) {
        this->waiting.push_back(kid);
    }

    void in() {
        if (this->waiting.size() >= 1) {
            auto kid = this->waiting.front();
            kid->set_debt(kid->get_debt() + 1);
            this->playing.push_back(kid);
            this->waiting.pop_front();
        } else {
            std::cout << "Não tem ninguém na fila!" << std::endl;
        }
    }

    void out() {
        if (this->playing.size() >= 1) {
            this->waiting.push_back(this->playing.front());
            this->playing.pop_front();
        } else {
            std::cout << "Não tem ninguém brincando!" << std::endl;
        }
    }

    std::shared_ptr<Kid> remove(std::string name) {
        auto kid = this->find_kid(name, this->playing);

        if (kid != this->playing.end()) {
            return this->remove_kid(kid, this->playing);
        }

        return nullptr;
    }

    std::string to_string() {
        std::stringstream output;

        for (auto it = this->waiting.rbegin(); it != this->waiting.rend(); it++) {
            output << (*it)->to_string() << " ";
        }

        output << "[ ";

        for (auto it = this->playing.rbegin(); it != this->playing.rend(); it++) {
            output << (*it)->to_string() << " ";
        }

        output << "]\nMoney: " << this->money;

        return output.str();
    }

    int saldo(std::string name) {
        auto kid_playing = this->find_kid(name, this->playing);
        auto kid_waiting = this->find_kid(name, this->waiting);

        if (kid_playing != this->playing.end()) {
            return (*kid_playing)->get_debt();
        } else if (kid_waiting != this->waiting.end()) {
            return (*kid_waiting)->get_debt();
        }

        return -1;
    }

    int caixa() {
        return this->money;
    }

    std::shared_ptr<Kid> papai_chegou(std::string name) {
        auto kid_playing = this->find_kid(name, this->playing);
        auto kid_waiting = this->find_kid(name, this->waiting);

        if (kid_playing != this->playing.end()) {
            return this->remove_kid(kid_playing, this->playing);
        } else if (kid_waiting != this->waiting.end()) {
            return this->remove_kid(kid_waiting, this->waiting);
        }

        return nullptr;
    }

    void fechar() {
        for (auto it = this->playing.begin(); it != this->playing.end(); it++) {
            this->remove_kid(it, this->playing);
            it = this->playing.begin();
        }

        for (auto it = this->waiting.begin(); it != this->waiting.end(); it++) {
            this->remove_kid(it, this->waiting);
            it = this->waiting.begin();
        }
    }
};