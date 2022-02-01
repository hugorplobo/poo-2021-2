#ifndef CONJUNTOS_HPP
#define CONJUNTOS_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila exclusivos(Fila fila) {
    std::sort(fila.begin(), fila.end());
    auto it = std::unique(fila.begin(), fila.end());
    return Fila(fila.begin(), it);
}

Fila diferentes(Fila fila) {
    std::for_each(fila.begin(), fila.end(), [](int &x) { x = std::abs(x); });
    std::sort(fila.begin(), fila.end());
    auto it = std::unique(fila.begin(), fila.end());
    return Fila(fila.begin(), it);
}

Fila abandonados(const Fila &fila) {
    Fila result;

    for (int i = 0; i < fila.size(); i++) {
        bool first = true;
        for (int j = 0; j < i; j++) {
            if (fila[i] == fila[j])
                first = false;
        }
        if (!first)
            result.push_back(fila[i]);
    }

    return result;
}

#endif