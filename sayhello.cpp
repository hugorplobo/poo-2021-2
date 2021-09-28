#include <iostream>

std::string sayHello(std::string name) {
    return "Hello, " + name;
}

int main() {
    std::string name;
    std::cout << "What's your name?\n> ";
    std::cin >> name;
    std::cout << sayHello(name) << std::endl;

    return 0;
}
