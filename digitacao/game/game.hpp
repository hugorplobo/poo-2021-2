#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <functional>
#include "../board/board.hpp"
#include "../pencil/pencil.hpp"
#include "../player/player.hpp"
#include "../menu/menu.hpp"
#include "../animated_sprite/animated_sprite.hpp"

class Game {
    sf::RenderWindow window;
    sf::Music background_music;
    AnimatedSprite background;
    Player player;
    Board board;
    Menu menu;
    std::function<void()> on_update;
    bool paused {false};

public:
    Game();

    void process_events();
    void gameplay();
    void menu_screen();
    void main_loop();
};