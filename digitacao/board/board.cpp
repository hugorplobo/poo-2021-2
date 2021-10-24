#include "board.hpp"

Board::Board(sf::RenderWindow& window) : window {window}, pencil{window} {}

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
    pencil.write("Hits: " + std::to_string(hits) + " Misses: " + std::to_string(misses), 10, 10, 20, sf::Color::White);
}

bool Board::check_new_bubble() {
    static const int new_bubble_timeout {60};
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
        if (bubble.alive && bubble.y + 2 * Bubble::radius > window.getSize().y) {
            bubble.alive = false;
            misses++;
        }
    }
}

void Board::mark_by_hit(char letter) {
    for (auto& bubble : bubbles) {
        if (bubble.letter == letter) {
            bubble.alive = false;
            hits++;
            break;
        }
    }
}

void Board::remove_dead_bubbles() {
    std::vector<Bubble> vivas;
    for (auto& bubble : bubbles) {
        if (bubble.alive) {
            vivas.push_back(bubble);
        }
    }

    bubbles = vivas;
}

void Board::add_new_bubble() {
    int x = rand() % (window.getSize().x - 2 * Bubble::radius);
    int y = -2 * Bubble::radius;
    int speed = rand() % 5 + 1;
    int letter = rand() % 26 + 'A';
    bubbles.push_back(Bubble(x, y, letter, speed));
}