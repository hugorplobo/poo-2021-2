#include "sala.hpp"
#include "../include/unit_tests.hpp"

Sala sala(5);

int main() {
    UnitTests tests;

    tests.add_test("Metodo to_string() retorna \"Hugo:9191\"", []() {
        Cliente hugo("Hugo", "9191");
        return UnitTests::assert_equals(hugo.to_string(), std::string("Hugo:9191"));
    });

    tests.add_test("Iniciar sala com 5 cadeiras", []() {
        return UnitTests::assert_equals(sala.to_string(), std::string("[ - - - - - ]"));
    });

    tests.add_test("Reservar sala para Hugo 9191", []() {
        sala.reservar("Hugo", "9191", 2);
        return UnitTests::assert_equals(sala.to_string(), std::string("[ - - Hugo:9191 - - ]"));
    });

    tests.add_test("Reservar sala ocupada", []() {
        return UnitTests::assert_false(sala.reservar("Maria", "3476", 2));
    });

    tests.add_test("Reservar outra cadeira", []() {
        sala.reservar("Pedro", "8021", 0);
        return UnitTests::assert_equals(sala.to_string(), std::string("[ Pedro:8021 - Hugo:9191 - - ]"));
    });

    tests.add_test("Cancelar reserva", []() {
        sala.cancelar("Hugo");
        return UnitTests::assert_equals(sala.to_string(), std::string("[ Pedro:8021 - - - - ]"));
    });

    tests.run_tests();
}