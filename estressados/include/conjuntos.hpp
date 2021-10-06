#ifndef CONJUNTOS_HPP
#define CONJUNTOS_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila exclusivos(const Fila &fila) {
    Fila result;

    for (int i = 0; i < fila.size(); i++) {
        bool unique = true;
        for (int j = 0; j < result.size(); j++) {
            if (fila[i] == result[j])
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
        for (int j = 0; j < result.size(); j++) {
            if (std::abs(fila[i]) == result[j])
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