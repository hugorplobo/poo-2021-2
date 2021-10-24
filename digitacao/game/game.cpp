#include "game.hpp"

#define WINDOW_W 800
#define WINDOW_H 600

Game::Game() : window(sf::VideoMode(WINDOW_W, WINDOW_H), "Typing"), board{window} {
    on_update = [&]() {
        gameplay();
    };
    window.setFramerateLimit(60);
}

void Game::process_events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::TextEntered) {
            char code = static_cast<char>(event.text.unicode);
            code = toupper(code);
            board.mark_by_hit(code);
        }
    }
}

void Game::gameplay() {
    board.update();
    window.clear();
    board.draw();
    window.display();
    if (board.misses > 10) {
        on_update = [&]() {
            gameover();
        };
    }
}

void Game::gameover() {
    static Pencil pencil(window);
    window.clear(sf::Color::Red);
    pencil.write("Game Over", 400, 300, 50, sf::Color::White);
    window.display();
}

void Game::main_loop() {
    while (window.isOpen()) {
        process_events();
        on_update();
    }
}
