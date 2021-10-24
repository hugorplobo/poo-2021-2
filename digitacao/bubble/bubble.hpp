#pragma once

#include <SFML/Graphics.hpp>
#include "../pencil/pencil.hpp"

class Bubble {
    int speed {1};

public:
    int x {0};
    int y {0};
    char letter {'a'};
    bool alive {true};
    static const int radius {20};

    Bubble(int x, int y, char letter, int speed);
    void update();
    void draw(sf::RenderWindow& window);
};