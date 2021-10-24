#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "../board/board.hpp"
#include "../pencil/pencil.hpp"

class Game {
    sf::RenderWindow window;
    Board board;
    std::function<void()> on_update;

public:
    Game();

    void process_events();
    void gameplay();
    void gameover();
    void main_loop();
};