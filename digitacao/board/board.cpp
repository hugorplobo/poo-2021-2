#include "board.hpp"

Board::Board(sf::RenderWindow& window, Player& player) : window {window}, pencil{window}, player {player} {
    if (!hit_buffer.loadFromFile("assets/sounds/hit.ogg")) {
        std::cout << "Failed to load hit.ogg\n";
        exit(1);
    }

    if (!miss_buffer.loadFromFile("assets/sounds/miss.ogg")) {
        std::cout << "Failed to load miss.ogg\n";
        exit(1);
    }

    hit_sound.setBuffer(hit_buffer);
    hit_sound.setVolume(5);
    critical_hit_sound.setBuffer(hit_buffer);
    critical_hit_sound.setVolume(100);
    miss_sound.setBuffer(miss_buffer);
    miss_sound.setVolume(10);
}

void Board::update() {
    if (check_new_bubble()) {
        add_new_bubble();
    }

    for (auto& bubble : bubbles) {
        bubble.update();
    }

    mark_outside_bubbles();
    remove_dead_bubbles();
}

void Board::draw() {
    for (auto& bubble : bubbles) {
        bubble.draw(window);
    }

    pencil.write("Money: $" + std::to_string(player.money) + "\nCombo: " + std::to_string(player.current_combo), 10, 10, 30, sf::Color::White);
    pencil.write("Press ESC to open menu", 10, window.getSize().y - 50, 30, sf::Color::White);
}

bool Board::check_new_bubble() {
    static const int new_bubble_timeout {30};
    static int new_bubble_timer {0};

    new_bubble_timer--;
    if (new_bubble_timer <= 0) {
        new_bubble_timer = new_bubble_timeout;
        return true;
    }

    return false;
}

void Board::mark_outside_bubbles() {
    for (auto& bubble : bubbles) {
        if (bubble.alive && bubble.y + Bubble::size > window.getSize().y) {
            miss_sound.play();
            bubble.alive = false;
            int resources = player.writing_courses + player.ebooks + player.physical_books + player.literary_agents + player.reviwers + player.writers;
            player.money -= (player.equipments * 2) > resources ? 0 : resources - player.equipments + 1;
            player.current_combo = 0;
        }
    }
}

void Board::mark_by_hit(char letter) {
    bool find_one = false;
    for (auto& bubble : bubbles) {
        if (bubble.letter == letter) {
            bool critical = (rand() % 100) <= player.writing_courses ? true : false;
            int add_money = 1 + player.ebooks * 2 + player.physical_books * 10 + player.reviwers * player.current_combo / 2;
            bubble.alive = false;
            player.money += critical ? 2 * add_money : add_money;
            player.current_combo++;

            if (critical) {
                critical_hit_sound.play();
            } else {
                hit_sound.play();
            }

            return;
        }
    }

    if (!find_one) {
        player.current_combo = 0;
        int resources = player.writing_courses + player.ebooks + player.physical_books + player.literary_agents + player.reviwers + player.writers;
        player.money -= (player.equipments * 2) > resources ? 0 : resources - player.equipments;
        miss_sound.play();
    }
}

void Board::remove_dead_bubbles() {
    for (auto it = bubbles.begin(); it != bubbles.end();) {
        if (!it->alive) {
            it = bubbles.erase(it);
        } else {
            it++;
        }
    }
}

void Board::add_new_bubble() {
    int x = rand() % (window.getSize().x - Bubble::size);
    int y = -Bubble::size;
    int speed = rand() % 5 + 1;
    int letter = rand() % 26 + 'A';
    bubbles.emplace_back(x, y, letter, speed);
}