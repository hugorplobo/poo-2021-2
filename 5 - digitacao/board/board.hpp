#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include "../pencil/pencil.hpp"
#include "../bubble/bubble.hpp"
#include "../player/player.hpp"

class Board {
    Pencil pencil;
    sf::RenderWindow& window;
    std::list<Bubble> bubbles;
    Player& player;

    sf::SoundBuffer hit_buffer;
    sf::Sound hit_sound;
    sf::SoundBuffer miss_buffer;
    sf::Sound miss_sound;
    sf::Sound critical_hit_sound;

public:
    Board(sf::RenderWindow& window, Player& player);
    void update();
    void draw();
    bool check_new_bubble();
    void mark_outside_bubbles();
    void mark_by_hit(char letter);
    void remove_dead_bubbles();
    void add_new_bubble();
};