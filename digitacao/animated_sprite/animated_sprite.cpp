#include "animated_sprite.hpp"

AnimatedSprite::AnimatedSprite(int fps, std::string path, int frames_qtd, int width, int height) : fps {fps}, current_frame {0}, timer {0} {
    sprite.setPosition(0, 0);
    sf::Texture texture;

    for (int i = 0; i < frames_qtd; i++) {
        if (!texture.loadFromFile(path + std::to_string(i) + ".png")) {
            std::cout << "Failed to load " << path + std::to_string(i) + ".png" << std::endl;
            exit(1);
        }

        texture.setSmooth(true);
        textures.push_back(texture);
    }

    sprite.setTexture(textures[0]);
    auto rect = sprite.getLocalBounds();
    sprite.setScale((float) width / rect.width, (float) height / rect.height);
}

void AnimatedSprite::update() {
    timer++;
    if (timer > textures.size() / fps) {
        current_frame++;
        if (current_frame >= textures.size()) {
            current_frame = 0;
        }

        sprite.setTexture(textures[current_frame]);
        timer = 0;
    }
}

void AnimatedSprite::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}