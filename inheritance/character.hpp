#pragma once

#include <iostream>

class Character {
public:
    Character() {
        this->level = 1;
        this->xp = 0;
        this->hp = 10;
        this->ac = 8;
        this->strength = 8;
        this->constitution = 8;
        this->dextery = 8;
        this->intelligence = 8;
        this->wisdom = 8;
        this->charisma = 8;
    }

    Character(std::string name, int level, int xp, int hp, int ac, int strength, int constitution, int dextery, int intelligence, int wisdom, int charisma)
        : name {name}, level {level}, xp {xp}, hp {hp}, ac {ac}, strength {strength}, constitution {constitution}, dextery {dextery}, intelligence {intelligence}, wisdom {wisdom}, charisma {charisma} {}


    friend std::ostream& operator<<(std::ostream& os, const Character& c) {
        os << c.name << "\nHP: " << c.hp << "  AC: " << c.ac;
        os << "\nStr.: " << c.strength << "\nConst.: " << c.constitution;
        os << "\nDext.: " << c.dextery << "\nInt.: " << c.intelligence;
        os << "\nWis.: " << c.wisdom << "\nChar.: " << c.charisma;
        return os;
    }

protected:
    std::string name;
    int level;
    int xp;
    int hp;
    int ac;
    int strength;
    int constitution;
    int dextery;
    int intelligence;
    int wisdom;
    int charisma;
};
