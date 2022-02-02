#include "player.hpp"

Player::Player() {}

void Player::update() {
    static const int tick_timeout {120};
    static int timer {0};

    timer--;
    if (timer <= 0) {
        timer = tick_timeout;
        money += 50 * writers;
    }
}