#include "game.hpp"

#define WINDOW_W 800
#define WINDOW_H 600

Game::Game() : window(sf::VideoMode(WINDOW_W, WINDOW_H), "Typing"), board{window, player}, menu {window, player}, background {5, "assets/textures/background/bg", 30, WINDOW_W, WINDOW_H} {
    if (!background_music.openFromFile("assets/sounds/lofi.ogg")) {
        std::cout << "Failed to open lofi.ogg\n";
        exit(1);
    }

    background_music.setLoop(true);
    background_music.setVolume(20);
    background_music.play();

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
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            paused = !paused;
            if (paused) {
                on_update = [&]() { menu_screen(); };
            } else {
                on_update = [&]() { gameplay(); };
            }
        } else if (event.type == sf::Event::TextEntered && !paused) {
            char code = static_cast<char>(event.text.unicode);
            code = toupper(code);
            if (int(code) != 27) {
                board.mark_by_hit(code);
            }
        } else if (event.type == sf::Event::TextEntered) {
            char code = static_cast<char>(event.text.unicode);
            code = toupper(code);
            menu.handle_input(code);
        }
    }
}

void Game::gameplay() {
    board.update();
    player.update();
    window.clear();
    background.update();
    background.draw(window);
    board.draw();
    window.display();
}

void Game::menu_screen() {
    window.clear();
    menu.draw();
    window.display();
}

void Game::main_loop() {
    while (window.isOpen()) {
        process_events();
        on_update();
    }
}
