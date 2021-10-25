#pragma once

#include <SFML/Graphics.hpp>
#include "../player/player.hpp"
#include "../pencil/pencil.hpp"

class Menu {
    sf::RenderWindow& window;
    Pencil pencil;
    Player& player;
    sf::Vector2f position;
    sf::Vector2f size;

public:
    Menu(sf::RenderWindow& window, Player& player);
    void draw_menu_box();
    void draw_items();
    void draw_actions();
    void draw_contracts();
    void draw();
    void handle_input(char input);
};