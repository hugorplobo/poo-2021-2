#include "pencil.hpp"

Pencil::Pencil(sf::RenderWindow& window) : window {window} {
    if (!font.loadFromFile("assets/fonts/LEMONMILK-Regular.otf")) {
        std::cout << "Failed to load superstar font!" << std::endl;
        exit(1);
    }
    text.setFont(font);
}

void Pencil::write(std::string str, int x, int y, int size, sf::Color color) {
    text.setString(str);
    text.setCharacterSize(size);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}