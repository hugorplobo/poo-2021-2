#include <SFML/Graphics.hpp>
#include <iostream>

#define STEP 100

void setSize(sf::Sprite &sprite, int width, int height) {
    auto spriteRect = sprite.getLocalBounds();
    sprite.setScale((float) width / spriteRect.width, (float) height / spriteRect.height);
}

struct Entity {
    int x {0}, y {0}, step {0};
    sf::Sprite sprite;

    Entity(int x, int y, int step, sf::Texture &texture):
        x {x}, y {y}, step {step}, sprite(texture) {
    }
    
    void draw(sf::RenderWindow &window) {
        sprite.setPosition(x * step, y * step);
        setSize(sprite, step, step);
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

void moveEntity(sf::Keyboard::Key key, Entity &entity, std::vector<sf::Keyboard::Key> moveKeys) {
    if (key == moveKeys[0])
        entity.x--;
    else if (key == moveKeys[1])
        entity.y--;
    else if (key == moveKeys[2])
        entity.x++;
    else if (key == moveKeys[3])
        entity.y++;
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
    

    sf::Texture wolf_tex { loadTexture("assets/wolfr.png") };
    sf::Texture rabbit_tex { loadTexture("assets/rabbit.png") };
    sf::Texture grass_tex { loadTexture("assets/grass.jpg") };

    Entity wolf(1, 1, STEP, wolf_tex);
    Entity rabbit(3, 3, STEP, rabbit_tex);
    Board board(7, 5, STEP, grass_tex);

    sf::RenderWindow window(sf::VideoMode(board.rows * STEP, board.cols * STEP), "Lobinho");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                moveEntity(event.key.code, wolf, { sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S });
                moveEntity(event.key.code, rabbit, { sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down });
            }
        }

        window.clear();
        board.draw(window);
        wolf.draw(window);
        rabbit.draw(window);
        window.display();
    }
}