#include "bubble.hpp"

Bubble::Bubble(int x, int y, char letter, int speed) : 
x {x}, y {y}, letter {letter}, speed {speed} {}

void Bubble::update() {
    y += speed;
}

void Bubble::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(Bubble::radius);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::White);
    window.draw(circle);

    static Pencil pencil(window);
    pencil.write(std::string(1, letter), x + 0.5 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Blue);
}