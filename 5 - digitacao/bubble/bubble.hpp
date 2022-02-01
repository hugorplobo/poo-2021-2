#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bubble {
    int speed {1};
    sf::Texture texture;
    sf::Sprite sprite;

public:
    int x {0};
    int y {0};
    char letter {'a'};
    bool alive {true};
    static const int size {50};

    Bubble(int x, int y, char letter, int speed);
    void update();
    void draw(sf::RenderWindow& window);
};