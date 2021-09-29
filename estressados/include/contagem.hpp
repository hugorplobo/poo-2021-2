#ifndef CONTAGEM_HPP
#define CONTAGEM_HPP

#include <vector>
#include <algorithm>
#include <numeric>

typedef std::vector<int> Fila;

int _getHomensN(Fila fila) {
    return std::count_if(fila.begin(), fila.end(), [](int x) { return x > 0; });
}

int _getMulheresN(Fila fila) {
    return std::count_if(fila.begin(), fila.end(), [](int x) { return x < 0; });
}

double calcularStressMedio(Fila fila) {
    return double(std::accumulate(fila.begin(), fila.end(), 0, [](int x, int y) { return std::abs(x) + std::abs(y); })) / fila.size();
}

int maisHomensOuMulheres(Fila fila) {
    int homens = _getHomensN(fila);
    int mulheres = _getMulheresN(fila);

    if (homens > mulheres)
        return 1;
    else if (mulheres > homens)
        return -1;
    else
        return 0;
}

int qualMetadeEhMaisEstressada(Fila fila) {
    int middle = fila.size() / 2;
    int first = std::accumulate(fila.begin(), fila.begin() + middle, 0, [](int x, int y) { return std::abs(x) + std::abs(y); });
    int last = std::accumulate(fila.begin() + middle, fila.end(), 0, [](int x, int y) { return std::abs(x) + std::abs(y); });

    return first > last ? 1 : 2;
}

bool homensSaoMaisEstressados(Fila fila) {
    double homens = double(std::accumulate(fila.begin(), fila.end(), 0, [](int x, int y) { return y > 0 ? y + x : x; })) / _getHomensN(fila);
    double mulheres = double(std::accumulate(fila.begin(), fila.end(), 0, [](int x, int y) { return y < 0 ? std::abs(y) + x : x; })) / _getMulheresN(fila);

    return homens > mulheres ? true : false;
}

#endif