#include <iostream>
#include <vector>
#include "include/busca.hpp"
#include "include/melhor_caso.hpp"
#include "include/contagem.hpp"

using namespace std;

int main() {
    cout << existe({-1, -50, -99}, -1) << "\n"; // true
    cout << existe({-1, -50, -99}, 10) << "\n\n"; // false

    cout << contar({-1, -50, -1, -99}, -1) << "\n"; // 2
    cout << contar({-1, -50, -1, -99}, 10) << "\n\n"; // 0

    cout << procurarValor({-1, -50, -1, -99}, -50) << "\n"; // 1
    cout << procurarValor({-1, -50, -1, -99}, 10) << "\n\n"; // -1

    cout << procurarValorApartir({5, 3, -1, -50, -1, -99}, 0, -1) << "\n"; // 2
    cout << procurarValorApartir({5, 3, -1, -50, -1, -99}, 3, -1) << "\n"; // 4
    cout << procurarValorApartir({5, 3, -1, -50, -1, -99}, 4, -1) << "\n\n"; // 4

    cout << procurarMenor({5, 3, -1, -50, -1, -99}) << "\n\n"; // -99

    cout << procurarMenorPos({5, 3, -1, -50, -1, -99}) << "\n\n"; // 5

    cout << procurarMenorPosApartir({5, 3, -1, -50, -1, 10}, 3) << "\n\n"; // 3

    cout << procurarMelhorPosSe({5, 3, -1, -50, -1, -99}) << "\n"; // 1
    cout << procurarMelhorPosSe({-1, -50, -1, -99}) << "\n\n"; // -1

    cout << calcularStressMedio({-1, -50, -1, -99}) << "\n\n"; // 37.75
    
    cout << maisHomensOuMulheres({5, 3, -1, -50, -1, -99}) << "\n"; // "mulheres"
    cout << maisHomensOuMulheres({5, 3, 1, -50, -1, -99}) << "\n"; // "empate"
    cout << maisHomensOuMulheres({5, 3, 1, -50, -1, 99}) << "\n\n"; // "homens"

    cout << qualMetadeEhMaisEstressada({5, 3, -1, -50, -1, -99}) << "\n"; // "segunda"
    cout << qualMetadeEhMaisEstressada({50, 98, 2, -50, -1, -99}) << "\n"; // "empate"
    cout << qualMetadeEhMaisEstressada({-51, 99, 1, -50, -1, 99}) << "\n\n"; // "primeira"
}