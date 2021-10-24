#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../pencil/pencil.hpp"
#include "../bubble/bubble.hpp"

class Board {
    Pencil pencil;
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    int hits {0};

public:
    int misses {0};

    Board(sf::RenderWindow& window);
    void update();
    void draw();
    bool check_new_bubble();
    void mark_outside_bubbles();
    void mark_by_hit(char letter);
    void remove_dead_bubbles();
    void add_new_bubble();
};