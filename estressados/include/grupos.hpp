#ifndef GRUPOS_HPP
#define GRUPOS_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila _getHomensQtd(const Fila &fila) {
    Fila res(100, 0);
    for (auto pessoa : fila) {
        if (pessoa > 0) res[pessoa]++;
    }

    return res;
}

Fila _getMulheresQtd(const Fila &fila) {
    Fila res(100, 0);
    for (auto pessoa : fila) {
        if (pessoa < 0) res[std::abs(pessoa)]++;
    }

    return res;
}

Fila _getQtd(const Fila &fila) {
    Fila res(100, 0);
    for (auto pessoa : fila) {
        res[std::abs(pessoa)]++;
    }

    return res;
}

int casais(const Fila &fila) {
    Fila homensQtd = _getHomensQtd(fila), mulheresQtd = _getMulheresQtd(fila);
    int casais = 0;

    for (int i = 1; i < homensQtd.size(); i++) {
        if (homensQtd[i] != 0 && mulheresQtd[i] != 0) {
            if (homensQtd[i] == mulheresQtd[i])
                casais += homensQtd[i];
            else
                casais += std::min(homensQtd[i], mulheresQtd[i]) % std::max(homensQtd[i], mulheresQtd[i]);
        }
    }

    return casais;
}

int trios(const Fila &fila) {
    Fila qtd = _getQtd(fila);
    int trios = 0;
    for (auto pessoa : qtd) {
        if (pessoa % 3 == 0)
            trios += pessoa / 3;
    }

    return trios;
}

#endif