#ifndef PROXIMIDADE_HPP
#define PROXIMIDADE_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

int briga(const Fila &fila) {
    int cont = 0;
    for (int i = 1; i < fila.size() - 1; i++) {
        if (std::abs(fila[i]) > 50 && (std::abs(fila[i - 1]) > 30 && std::abs(fila[i + 1]) > 30))
            cont++;
    }

    return cont;
}

Fila apaziguados(const Fila &fila) {
    Fila res;
    for (int i = 0; i < fila.size(); i++)
        if (std::abs(fila[i]) > 80) {
            if (i == 0) {
                if (std::abs(fila[i + 1]) < 10)
                    res.push_back(i);
            } else if (i == fila.size() - 1) {
                if (std::abs(fila[i - 1]) < 10)
                    res.push_back(i);
            } else {
                if (std::abs(fila[i - 1]) < 10 || std::abs(fila[i + 1]) < 10)
                    res.push_back(i);
            }
        }

    return res;
}

#endif