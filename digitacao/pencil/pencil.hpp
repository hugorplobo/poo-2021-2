#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Pencil {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

public:
    Pencil(sf::RenderWindow& window);
    void write(std::string str, int x, int y, int size, sf::Color color);
};