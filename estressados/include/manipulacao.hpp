#ifndef MANIPULACAO_HPP
#define MANIPULACAO_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

Fila sozinhos(const Fila &fila) {
    Fila res;
    for (auto pessoa : fila) {
        if (std::count_if(fila.begin(), fila.end(), [pessoa](int x) { return std::abs(x) == std::abs(pessoa); }) == 1)
            res.push_back(pessoa);
    }

    return res;
}

Fila _getOcorrencias(const Fila &fila) {
    Fila ocorrencias(100, 0);
    for (auto pessoa : fila)
        ocorrencias[std::abs(pessoa)]++;
    
    return ocorrencias;
}

int maisOcorrencias(const Fila &fila) {
    Fila ocorrencias = _getOcorrencias(fila);
    return *std::max_element(ocorrencias.begin(), ocorrencias.end());
}

Fila maisRecorrentes(const Fila &fila) {
    Fila ocorrencias = _getOcorrencias(fila);
    Fila res;
    int max = 0;

    for (auto ocorrencia : ocorrencias) 
        if (ocorrencia > max) max = ocorrencia;

    for (int i = 0; i < ocorrencias.size(); i++)
        if (ocorrencias[i] == max) res.push_back(i);
    
    return res;
}

#endif