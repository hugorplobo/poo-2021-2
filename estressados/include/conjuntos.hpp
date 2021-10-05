#ifndef CONJUNTOS_HPP
#define CONJUNTOS_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila exclusivos(const Fila &fila) {
    Fila result;

    for (int i = 0; i < fila.size(); i++) {
        bool unique = true;
        for (int j = 0; j < fila.size(); j++) {
            if (i != j && fila[i] == fila[j])
                unique = false;
        }

        if (unique)
            result.push_back(fila[i]);
    }

    return result;
}

Fila diferentes(const Fila &fila) {
    Fila result;

    for (int i = 0; i < fila.size(); i++) {
        bool unique = true;
        for (int j = 0; j < fila.size(); j++) {
            if (i != j && std::abs(fila[i]) == std::abs(fila[j]))
                unique = false;
        }

        if (unique)
            result.push_back(std::abs(fila[i]));
    }

    return result;
}

Fila abandonados(const Fila &fila) {
    Fila result;

    for (int i = 0; i < fila.size(); i++) {
        if (std::find(result.begin(), result.end(), fila[i]) == result.end())
            result.push_back(fila[i]);
    }

    return result;
}

#endif