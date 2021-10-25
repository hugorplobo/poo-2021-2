#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class AnimatedSprite {
    sf::Sprite sprite;
    std::vector<sf::Texture> textures;
    int fps;
    int current_frame;
    int timer;

public:
    AnimatedSprite(int fps, std::string path, int frames_qtd, int width, int height);
    void update();
    void draw(sf::RenderWindow& window);
};