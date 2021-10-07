#ifndef ACESSO_HPP
#define ACESSO_HPP

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

typedef std::vector<int> Fila;

Fila inverterComCopia(const Fila &fila) {
    Fila result(fila.size());
    std::reverse_copy(fila.begin(), fila.end(), result.begin());

    return result;
}

void reverterInplace(Fila &fila) {
    std::reverse(fila.begin(), fila.end());
}

int sortear(const Fila &fila) {
    std::srand(std::time(NULL));
    return fila[std::rand() % (fila.size() - 1)];
}

void embaralhar(Fila &fila) {
    std::srand(std::time(NULL));
    std::random_shuffle(fila.begin(), fila.end(), [](int x) { return std::rand() % x; });
}

void ordenar(Fila &fila) {
    std::sort(fila.begin(), fila.end());
}

#endif