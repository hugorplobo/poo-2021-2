#include "kid.hpp"
#include "trampoline.hpp"
#include "../include/unit_tests.hpp"

Trampoline tramp;

int main() {
    UnitTests tests;

    tests.add_test("Metodo to_string() retorna \"Hugo: 18\"", []() {
        Kid hugo("hugo", 18);
        return UnitTests::assert_equals(hugo.to_string(), std::string("Hugo: 18"));
    });

    tests.add_test("Adicionar crianca na fila", []() {
        tramp.arrive(std::make_shared<Kid>("hugo", 12));
        return UnitTests::assert_equals(tramp.to_string(), std::string("Hugo: 12 [ ]\nMoney: 0"));
    });

    tests.add_test("Adiciona segunda crianca na fila", []() {
        tramp.arrive(std::make_shared<Kid>("maria", 13));
        return UnitTests::assert_equals(tramp.to_string(), std::string("Maria: 13 Hugo: 12 [ ]\nMoney: 0"));
    });

    tests.add_test("Adicionar crianca no trampolim", []() {
        tramp.in();
        return UnitTests::assert_equals(tramp.to_string(), std::string("Maria: 13 [ Hugo: 12 ]\nMoney: 0"));
    });

    tests.add_test("Remover crianca do trampolim", []() {
        tramp.out();
        return UnitTests::assert_equals(tramp.to_string(), std::string("Hugo: 12 Maria: 13 [ ]\nMoney: 0"));
    });

    tests.add_test("O papai chegou", []() {
        tramp.papai_chegou("maria");
        return UnitTests::assert_equals(tramp.to_string(), std::string("Hugo: 12 [ ]\nMoney: 0"));
    });

    tests.add_test("Saldo", []() {
        return UnitTests::assert_equals(tramp.saldo("hugo"), 1);
    });

    tests.add_test("Fechar", []() {
        tramp.fechar();
        return UnitTests::assert_equals(tramp.to_string(), std::string("[ ]\nMoney: 1"));
    });

    tests.run_tests();
}