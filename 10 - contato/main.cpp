#include <iostream>
#include "contato.hpp"

int main() {
    Contact hugo("Hugo", {});
    hugo.add_fone(std::make_shared<Fone>("Casa", "(88)35125655"));
    hugo.add_fone(std::make_shared<Fone>("Celular", "(88)981440485"));

    std::cout << hugo << std::endl;

    hugo.rm_fone(1);
    std::cout << hugo << std::endl;
}