#ifndef ALTERACAO_HPP
#define ALTERACAO_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila remove(const Fila &fila, int pessoa) {
    Fila clone(fila);
    clone.erase(std::find(clone.begin(), clone.end(), pessoa));
    return clone;
}

Fila insert(const Fila &fila, int pessoa, int pos) {
    Fila clone(fila);
    clone.insert(clone.begin() + pos, pessoa);
    return clone;
}

Fila dance(const Fila &fila) {
    Fila clone(fila);
    for (auto it = clone.begin(); it != clone.end() - 1; it++) {
        if (std::abs(*it) == std::abs(*(it + 1))) {
            clone.erase(it, it + 2);
            it = clone.begin() - 1;
        }
    }

    return clone;
}

#endif