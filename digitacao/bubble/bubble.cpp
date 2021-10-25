#include "bubble.hpp"

void set_size(sf::Sprite& sprite, int width, int height) {
    auto rect = sprite.getLocalBounds();
    sprite.setScale((float) width / rect.width, (float) height / rect.height);
}

Bubble::Bubble(int x, int y, char letter, int speed) : 
x {x}, y {y}, letter {letter}, speed {speed} {
    if (!texture.loadFromFile("assets/textures/letters/" + std::string(1, letter) + ".png")) {
        std::cout << "Failed to load letter " << letter << std::endl;
        exit(1);
    }

    texture.setSmooth(false);
    sprite.setTexture(texture);
    set_size(sprite, 80, 80);
    auto rect = sprite.getLocalBounds();
}

void Bubble::update() {
    y += speed;
}

void Bubble::draw(sf::RenderWindow& window) {
    sprite.setPosition(x, y);
    window.draw(sprite);
}