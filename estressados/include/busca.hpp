#ifndef BUSCA_HPP
#define BUSCA_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

bool existe(Fila fila, int value) {
    if (std::find(fila.begin(), fila.end(), value) != fila.end())
        return true;
    
    return false;
}

int contar(Fila fila, int value) {
    return std::count(fila.begin(), fila.end(), value);
}

int procurarValor(Fila fila, int value) {
    auto found = std::find(fila.begin(), fila.end(), value);

    if (found == fila.end())
        return -1;
    
    return std::distance(fila.begin(), found);
}

int procurarValorApos(Fila fila, int pos, int value) {
    if (pos < 0 || pos > fila.size() - 1)
        return -1;

    int indexFound = procurarValor(Fila(fila.begin() + pos + 1, fila.end()), value);

    return indexFound != -1 ? pos + 1 + indexFound : -1;
}

#endif