#ifndef MELHOR_CASO_HPP
#define MELHOR_CASO_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila::iterator _procurarMenorIterator(Fila& fila) {
    return std::min_element(fila.begin(), fila.end());
}

Fila::iterator _procurarMaiorIterator(Fila& fila) {
    return std::max_element(fila.begin(), fila.end());
}

int procurarMenor(Fila fila) {
    return *_procurarMenorIterator(fila);
}

int procurarMaior(Fila fila) {
    return *_procurarMaiorIterator(fila);
}

int procurarMenorPos(Fila fila) {
    return std::distance(fila.begin(), _procurarMenorIterator(fila));
}

int procurarMaiorPos(Fila fila) {
    return std::distance(fila.begin(), _procurarMenorIterator(fila));
}

int procurarMenorPosApartir(Fila fila, int pos) {
    if (pos < 0 || pos > fila.size() - 1)
        return -1;

    auto filaTemp = Fila(fila.begin() + pos, fila.end());
    return pos + std::distance(_procurarMenorIterator(filaTemp), filaTemp.begin());
}

int procurarMelhorPosSe(Fila fila) {
    auto indexFound = std::find_if(fila.begin(), fila.end(), [](int x) { return x > 0; });
    auto minValue = std::find_if(fila.begin(), fila.end(), [&](int x) { return x > 0 && x < *indexFound; });
    if (minValue != fila.end())
        return std::distance(fila.begin(), minValue);
    
    return -1;
}

#endif