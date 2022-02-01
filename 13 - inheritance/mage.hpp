#pragma once

#include <iostream>
#include <vector>
#include "character.hpp"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << (i == v.size() - 1 ? " " : ", ");
    }
    os << "]";
    return os;
}

class Mage : public Character {
public:
    Mage(const std::string& name, int level, int xp, int hp, int ac, int strength, int constitution, int dextery, int intelligence, int wisdom, int charisma, int spell_slots, std::vector<std::string> grimory) : Character(name, level, xp, hp, ac, strength, constitution, dextery, intelligence, wisdom, charisma), spell_slots {spell_slots}, grimory {grimory} {}

    void prepare_spell(int index) {
        this->prepared_spells.push_back(this->grimory[index]);
    }

    friend std::ostream& operator<<(std::ostream& os, const Mage& m) {
        os << "Mage, " << m.level << " (" << m.xp << " XP)\n";
        os << (Character) m << "\n";
        os << "Spell slots: " << m.spell_slots << "\n";
        os << "Grimory: " << m.grimory << "\n";
        os << "Prepared spells: " << m.prepared_spells << "\n";
        return os;
    }

private:
    int spell_slots;
    std::vector<std::string> grimory;
    std::vector<std::string> prepared_spells;
};
