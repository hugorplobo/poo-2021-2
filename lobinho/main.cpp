#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define STEP 100

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

void setSize(sf::Sprite &sprite, int width, int height) {
    auto spriteRect = sprite.getLocalBounds();
    sprite.setScale((float) width / spriteRect.width, (float) height / spriteRect.height);
}

struct Entity {
    int x {0}, y {0}, step {0}, hp {0};
    sf::Sprite sprite;
    Direction direction { RIGHT };

    Entity(int x, int y, int step, int hp, sf::Texture &texture):
        x {x}, y {y}, step {step}, hp {hp}, sprite(texture) {
        setSize(sprite, step, step);
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    }
    
    void draw(sf::RenderWindow &window) {
        sprite.setPosition(x * step + 50, y * step + 50);
        window.draw(sprite);
    }
};

struct Board {
    int rows {0}, cols {0}, step {0};
    sf::Sprite sprite;
    sf::RectangleShape rect;

    Board(int rows, int cols, int step, sf::Texture &texture):
        rows {rows}, cols {cols}, step {step}, sprite {texture} {
        setSize(sprite, rows * step, cols * step);
        sprite.setPosition(0, 0);

        rect.setSize(sf::Vector2f(step, step));
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::Black);
        rect.setOutlineThickness(2);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(sprite);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rect.setPosition(i * step, j * step);
                window.draw(rect);
            }
        }
    }
};

void spawnZombie(std::vector<Entity> &zombies, sf::Texture &zombie_tex) {
    int x = rand() % 7, y = rand() % 5;
    zombies.push_back(Entity(x, y, STEP, 0, zombie_tex));
}

void shoot(std::vector<Entity> &zombies, Entity &survivor) {
    for (auto it = zombies.begin(); it != zombies.end(); it++) {
        if (survivor.direction == LEFT) {
            if (it->x < survivor.x && it->y == survivor.y) {
                zombies.erase(it);
                break;
            }
        } else if (survivor.direction == RIGHT) {
            if (it->x > survivor.x && it->y == survivor.y) {
                zombies.erase(it);
                break;
            }
        } else if (survivor.direction == UP) {
            if (it->y < survivor.y && it->x == survivor.x) {
                zombies.erase(it);
                break;
            }
        } else {
            if (it->y > survivor.y && it->x == survivor.x) {
                zombies.erase(it);
                break;
            }
        }
    }
}

void handleKeyboard(sf::Keyboard::Key key, Entity &entity, std::vector<Entity> &zombies) {
    if (key == sf::Keyboard::A) {
        entity.sprite.setRotation(-180);
        entity.direction = LEFT;
        entity.x--;
    } else if (key == sf::Keyboard::W) {
        entity.sprite.setRotation(-90);
        entity.direction = UP;
        entity.y--;
    } else if (key == sf::Keyboard::D) {
        entity.sprite.setRotation(0);
        entity.direction = RIGHT;
        entity.x++;
    } else if (key == sf::Keyboard::S) {
        entity.sprite.setRotation(90);
        entity.direction = DOWN;
        entity.y++;
    } else if (key == sf::Keyboard::Space) {
        shoot(zombies, entity);
    }
}

void updateZombies(std::vector<Entity> &zombies, Entity &survivor) {
    for (auto &zombie : zombies) {
        if (zombie.x > survivor.x) {
            handleKeyboard(sf::Keyboard::A, zombie, zombies);
        } else if (zombie.x < survivor.x) {
            handleKeyboard(sf::Keyboard::D, zombie, zombies);
        } else if (zombie.y < survivor.y) {
            handleKeyboard(sf::Keyboard::S, zombie, zombies);
        } else if (zombie.y > survivor.y) {
            handleKeyboard(sf::Keyboard::W, zombie, zombies);
        }
    }
}

void checkCollisions(std::vector<Entity> &zombies, Entity &survivor, bool &lose) {
    for (auto zombie : zombies) {
        if (zombie.x == survivor.x && zombie.y == survivor.y)
            survivor.hp--;
    }

    if (survivor.hp < 1)
        lose = true;
}

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Failed to load " << path <<  " texture\n";
        exit(1);
    }

    return texture;
}

int main() {
    std::srand(std::time(NULL));

    sf::Texture survivor_tex { loadTexture("assets/survivor.png") };
    sf::Texture zombie_tex { loadTexture("assets/zombie.png") };
    sf::Texture road_tex { loadTexture("assets/road.png") };
    sf::Font OctoberCrow;

    if (!OctoberCrow.loadFromFile("assets/OctoberCrow.ttf")) {
        std::cout << "Failed to load assets/OctoberCrow.ttf font\n";
        exit(1);
    }

    sf::Text hpText;

    std::vector<Entity> zombies;
    Entity survivor(1, 1, STEP, 3, survivor_tex);
    Board board(7, 5, STEP, road_tex);
    int timer {0};
    bool lose = false;

    hpText.setString("Vidas: " + std::to_string(survivor.hp));
    hpText.setFillColor(sf::Color::Red);
    hpText.setCharacterSize(64);
    hpText.setPosition(10, 10);
    hpText.setFont(OctoberCrow);

    sf::RenderWindow window(sf::VideoMode(board.rows * STEP, board.cols * STEP), "Lobinho");
    window.setFramerateLimit(60);

    while(window.isOpen() && !lose) {
        if (timer == 60) {
            spawnZombie(zombies, zombie_tex);
            updateZombies(zombies, survivor);
            checkCollisions(zombies, survivor, lose);
            timer = 0;
        } else {
            timer++;
        }

        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                handleKeyboard(event.key.code, survivor, zombies);
            }
        }

        hpText.setString("Vidas: " + std::to_string(survivor.hp));

        window.clear();
        board.draw(window);
        survivor.draw(window);
        for (auto zombie : zombies) {
            zombie.draw(window);
        }
        window.draw(hpText);
        window.display();
    }
}
