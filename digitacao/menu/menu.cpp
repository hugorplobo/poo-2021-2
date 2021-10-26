#include "menu.hpp"

/*

- Possiveis compras
    - Curso de escrita: chance de acerto duplo
    - Melhorar equipamento: diminui perda em erros

- Ações
    - Publicar livro: aumenta ganho por letra

- Contratar
    - Agente literário: diminui preço de publicar livro
    - Revisor: aumenta ganho por letra baseado no combo atual
    - Escritor: ganho passivo de dinheiro

*/

Menu::Menu(sf::RenderWindow& window, Player& player) : window {window}, player {player}, pencil {window} {
    if (!buy_buffer.loadFromFile("assets/sounds/buy.ogg")) {
        std::cout << "Failed to load buy.ogg\n";
        exit(1);
    }

    buy_sound.setBuffer(buy_buffer);
    buy_sound.setVolume(10);

    size.x = window.getSize().x - 100;
    size.y = window.getSize().y - 80;
    position.x = window.getSize().x / 2 - size.x / 2;
    position.y = window.getSize().y / 2 - size.y / 2;
}

void Menu::draw() {
    draw_menu_box();
    draw_items();
    draw_actions();
    draw_contracts();
    pencil.write("Money: $" + std::to_string(player.money), position.x + 12, position.y + 10, 22, sf::Color::White);
}

void Menu::draw_menu_box() {
    sf::RectangleShape menu_box;
    menu_box.setSize(size);
    menu_box.setFillColor(sf::Color::Black);
    menu_box.setOutlineColor(sf::Color::White);
    menu_box.setOutlineThickness(2);
    menu_box.setPosition(position);
    window.draw(menu_box);
}

void Menu::draw_items() {
    std::string to_render {"Itens: \n\t[1] - $" + std::to_string(player.writing_courses_cost) + " Curso de escrita: Aumenta a chance de acerto\n\tdobrado"  + "\n\t[2] - $" + std::to_string(player.equipments_cost) + " Melhorar equipamento: Reduz a perda de dinheiro\n\tem erros"};
    pencil.write(to_render, position.x + 12, position.y + 60, 18, sf::Color::White);
}

void Menu::draw_actions() {
    std::string to_render {"Acoes: \n\t[3] - $" + std::to_string(player.ebooks_cost) + " Publicar um ebook: Aumenta um pouco o lucro\n\tpor letra" + "\n\t[4] - $" + std::to_string(player.physical_books_cost) + " Publicar um livro fisico: Aumenta muito o lucro\n\tpor letra"};
    pencil.write(to_render, position.x + 12, position.y + 200, 18, sf::Color::White);
}

void Menu::draw_contracts() {
    std::string to_render {"Contratos: \n\t[5] - $" + std::to_string(player.literary_agents_cost) + " Agente literario: Torna mais barato publicar\n\tlivros" + "\n\t[6] - $" + std::to_string(player.reviwers_cost) + " Reviewer: Aumenta o lucro por letra baseado no\n\tcombo atual" + "\n\t[7] - $" + std::to_string(player.writers_cost) + " Writer: Ganho passivo de dinheiro"};
    pencil.write(to_render, position.x + 12, position.y + 340, 18, sf::Color::White);
}

void Menu::handle_input(char input) {
    switch (input) {
    case '1':
        if (player.money >= player.writing_courses_cost) {
            buy_sound.play();
            player.money -= player.writing_courses_cost;
            player.writing_courses_cost += player.writing_courses_cost / 2.0;
            player.writing_courses++;
        }
        break;

    case '2':
        if (player.money >= player.equipments_cost) {
            player.money -= player.equipments_cost;
            player.equipments_cost += player.equipments_cost / 2.0;
            player.equipments++;
            buy_sound.play();
        }
        break;

    case '3':
        if (player.money >= player.ebooks_cost) {
            player.money -= player.ebooks_cost;
            player.ebooks_cost += player.ebooks_cost / 2.0;
            player.ebooks++;
            buy_sound.play();
        }
        break;
    
    case '4':
        if (player.money >= player.physical_books_cost) {
            player.money -= player.physical_books_cost;
            player.physical_books_cost += player.physical_books_cost / 2.0;
            player.physical_books++;
            buy_sound.play();
        }
        break;
    
    case '5':
        if (player.money >= player.literary_agents_cost) {
            player.money -= player.literary_agents_cost;
            player.literary_agents_cost += player.literary_agents_cost / 2.0;
            player.literary_agents++;
            player.ebooks_cost -= player.literary_agents * 100;
            player.physical_books_cost -= player.literary_agents * 100;
            buy_sound.play();
        }
        break;
    
    case '6':
        if (player.money >= player.reviwers_cost) {
            player.money -= player.reviwers_cost;
            player.reviwers_cost += player.reviwers_cost / 2.0;
            player.reviwers++;
            buy_sound.play();
        }
        break;
    
    case '7':
        if (player.money >= player.writers_cost) {
            player.money -= player.writers_cost;
            player.writers_cost += player.writers_cost / 2.0;
            player.writers++;
            buy_sound.play();
        }
        break;
    
    default:
        break;
    }
}