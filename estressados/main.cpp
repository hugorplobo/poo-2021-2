#include <iostream>
#include <vector>
#include "include/busca.hpp"
#include "include/melhor_caso.hpp"
#include "include/contagem.hpp"
#include "include/tests.hpp"

using namespace std;

void testarBusca() {
    cout << "\nTestes de busca: \n";
    testar(existe({-1, -50, -99}, -1), true);
    testar(existe({-1, -50, -99}, 10), false);
    testar(contar({-1, -50, -1, -99}, -1), 2);
    testar(contar({-1, -50, -1, -99}, 10), 0);
    testar(procurarValor({-1, -50, -1, -99}, -50), 1);
    testar(procurarValor({-1, -50, -1, -99}, 10), -1);
    testar(procurarValorApartir({5, 3, -1, -50, -1, -99}, 0, -1), 2);
    testar(procurarValorApartir({5, 3, -1, -50, -1, -99}, 3, -1), 4);
    testar(procurarValorApartir({5, 3, -1, -50, -1, -99}, 4, -1), 4);
}

void testarMelhorCaso() {
    cout << "\nTestes de melhor caso: \n";
    testar(procurarMenor({5, 3, -1, -50, -1, -99}), -99);
    testar(procurarMenorPos({5, 3, -1, -50, -1, -99}), 5);
    testar(procurarMenorPosApartir({5, 3, -1, -50, -1, 10}, 3), 3);
    testar(procurarMelhorPosSe({5, 3, -1, -50, -1, -99}), 1);
    testar(procurarMelhorPosSe({-1, -50, -1, -99}), -1);
}

void testarContagem() {
    cout << "\nTestes de contagem: \n";
    testar(calcularStressMedio({-1, -50, -1, -99}), 37.75);
    testar(maisHomensOuMulheres({5, 3, -1, -50, -1, -99}), string("mulheres"));
    testar(maisHomensOuMulheres({5, 3, 1, -50, -1, -99}), string("empate"));
    testar(maisHomensOuMulheres({5, 3, 1, -50, -1, 99}), string("homens"));
    testar(qualMetadeEhMaisEstressada({5, 3, -1, -50, -1, -99}), string("segunda"));
    testar(qualMetadeEhMaisEstressada({50, 98, 2, -50, -1, -99}), string("empate"));
    testar(qualMetadeEhMaisEstressada({-51, 99, 1, -50, -1, 99}), string("primeira"));
    testar(homensSaoMaisEstressados({5, 3, -1, -50, -1, -99}), false);
}

int main() {
    testarBusca();
    testarMelhorCaso();
    testarContagem();
}