#include <iostream>
#include "character.hpp"
#include "mage.hpp"

int main() {
    Character jorge("Jorge", 1, 20, 12, 14, 15, 16, 12, 8, 10, 10);
    Mage hugo("Hugo", 5, 1800, 22, 18, 12, 12, 16, 20, 18, 16, 6, {"Fire Ball", "Magic Missiles"});

    hugo.prepare_spell(0);

    std::cout << jorge << std::endl << std::endl;
    std::cout << hugo << std::endl;
}
