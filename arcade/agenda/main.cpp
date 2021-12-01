#include <iostream>
#include "agenda.hpp"

int main() {
    Agenda agenda;

    auto jp = std::make_shared<Contact>("Jp", std::vector<std::shared_ptr<Fone>>());
    jp->add_fone(std::make_shared<Fone>("Celular", "(81)98743205"));

    auto jonatas = std::make_shared<Contact>("Jonatas", std::vector<std::shared_ptr<Fone>>());
    jonatas->add_fone(std::make_shared<Fone>("Celular", "(85)76590031"));

    auto hugo = std::make_shared<Contact>("Hugo", std::vector<std::shared_ptr<Fone>>());
    hugo->add_fone(std::make_shared<Fone>("Casa", "(88)35125655"));

    auto felipe = std::make_shared<Contact>("Felipe", std::vector<std::shared_ptr<Fone>>());
    felipe->add_fone(std::make_shared<Fone>("Celular", "(88)87654321"));

    agenda.add_contact(jp);
    agenda.add_contact(hugo);
    agenda.add_contact(felipe);
    agenda.add_contact(jonatas);

    std::cout << agenda << std::endl;

    auto res = agenda.search("");

    for (auto &i : res) {
        std::cout << *i << std::endl;
    }
}