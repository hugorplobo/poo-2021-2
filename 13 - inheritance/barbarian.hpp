#pragma once

#include <iostream>
#include "character.hpp"

class Barbarian : public Character {
public:
    Barbarian(const std::string& name, int level, int xp, int hp, int ac, int strength, int constitution, int dextery, int intelligence, int wisdom, int charisma, int rage, int attacks) : Character(name, level, xp, hp, ac, strength, constitution, dextery, intelligence, wisdom, charisma), rage {rage}, attacks {attacks} {}

    void in_rage() {
        if (this->rage > 0) {
            this->rage--;
            this->strength++;
            this->attacks++;
        }
    }

    void receive_damage(int damage) {
        this->hp -= damage;
        this->rage++;
    }

    friend std::ostream& operator<<(std::ostream& os, const Barbarian& m) {
        os << "Barbarian, " << m.level << " (" << m.xp << " XP)\n";
        os << (Character) m << "\n";
        os << "Rage points: " << m.rage << "\n";
        os << "Attacks per turn: " << m.attacks << "\n";
        return os;
    }

private:
    int rage;
    int attacks;
};
