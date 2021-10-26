#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    int money {100};
    int current_combo {0};
    int writing_courses {0};
    int equipments {0};
    int ebooks {0};
    int physical_books {0};
    int literary_agents {0};
    int reviwers {0};
    int writers {0};

    int writing_courses_cost {10};
    int equipments_cost {10};
    int ebooks_cost {200};
    int physical_books_cost {1000};
    int literary_agents_cost {10000};
    int reviwers_cost {1000};
    int writers_cost {1000};

    Player();
    void update();
};