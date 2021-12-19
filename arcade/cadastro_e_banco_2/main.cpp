#include <iostream>
#include "bank.hpp"

int main() {
    Bank banco;
    banco.addClient("Hugo");

    std::cout << banco << std::endl;

    banco.deposit(0, 200);
    banco.deposit(1, 700);

    banco.monthly_update();

    std::cout << banco;
}