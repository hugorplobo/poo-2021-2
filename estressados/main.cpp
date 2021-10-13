#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "include/busca.hpp"
#include "include/melhor_caso.hpp"
#include "include/contagem.hpp"
#include "include/filter.hpp"
#include "include/acesso.hpp"
#include "include/conjuntos.hpp"
#include "include/manipulacao.hpp"
#include "include/proximidade.hpp"
#include "include/sequencias.hpp"
#include "include/grupos.hpp"
#include "include/alteracao.hpp"
#include "include/tests.hpp"

using namespace std;

typedef std::vector<int> Fila;

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

void testarFilter() {
    cout << "\nTestes de filtragem: \n";
    testar(clone({5, 3, -1, -50, -1, -99}), {5, 3, -1, -50, -1, -99});
    testar(copiarHomens({5, 3, -1, -50, -1, -99}), {5, 3});
    testar(copiarCalmos({5, 3, -1, -50, -1, -99}), {5, 3, -1, -1});
    testar(copiarMulheresCalmas({5, 3, -1, -50, -1, -99}), {-1, -1});
}

void testarAcesso() {
    cout << "\nTestes de acesso: \n";
    testar(inverterComCopia({5, 3, -1, -50, -1, -99}), {-99, -1, -50, -1, 3, 5});
}

void testarConjuntos() {
    cout << "\nTestes de conjuntos: \n";
    testar(exclusivos({5, 3, -1, -50, -1, 5}), {-50, -1, 3, 5});
    testar(diferentes({5, 3, -1, -50, 1, -99}), {1, 3, 5, 50, 99});
    testar(abandonados({5, 3, -1, -50, -1, -99}), {-1});
}

void testarManipulacao() {
    cout << "\nTestes de manipulação: \n";
    testar(sozinhos({1, 3, 4, 3, -1, -3, -3}), {4});
    testar(maisOcorrencias({1, 3, 4, 5, -1, -5, -5}), 3);
    testar(maisRecorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3}), {3, 5});
}

void testarProximidade() {
    cout << "\nTestes de proximidade: \n";
    testar(briga({-89, 34, -90, 99, 87, 10}), 2);
    testar(apaziguados({89, -8, -4, -95, 99, 45}), {0, 3});
}

void testarSequencias() {
    cout << "\nTestes de sequências: \n";
    testar(quantosTimes({2, 99, 87, -9, 8, -10, -45}), 2);
    testar(maiorTime({2, 99, 87, -9, 8, -10, -45}), {2, 99, 87});
    testar(semTime({2, 99, 87, -9, 8, -10, -45}), 2);
}

void testarGrupos() {
    cout << "\nTestes de grupos: \n";
    testar(casais({-4, -98, -74, -35, -43, -10, 98, 98, 35, 43}), 3);
    testar(trios({-2, 2, 40, 99, 2, -40, 98, 40}), 2);
}

void testarAlteracao() {
    cout << "\nTestes de alteração: \n";
    testar(remove({2, 99, 87, -9, 8, -10, -45}, 8), {2, 99, 87, -9, -10, -45});
    testar(insert({2, 99, 87, -9, -10, -45}, 5, 3), {2, 99, 87, 5, -9, -10, -45});
    testar(dance({3, 4, -4, -3, 5}), {5});
}

int main() {
    srand(time(NULL));

    testarBusca();
    testarMelhorCaso();
    testarContagem();
    testarFilter();
    testarAcesso();
    testarConjuntos();
    testarManipulacao();
    testarProximidade();
    testarSequencias();
    testarGrupos();
    testarAlteracao();
}