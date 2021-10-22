#ifndef SEQUENCIAS_HPP
#define SEQUENCIAS_HPP

#include <vector>
#include <algorithm>

typedef std::vector<int> Fila;

int _getSign(int num) {
    return num / std::abs(num);
}

std::vector<Fila> _getTimes(const Fila &fila) {
    int sign = _getSign(fila[0]), timesQtd = 0;
    std::vector<Fila> times(fila.size());

    for (int i = 0; i < fila.size(); i++) {
        if (_getSign(fila[i]) == sign) {
            times[timesQtd].push_back(fila[i]);
        } else {
            timesQtd++;
            times[timesQtd].push_back(fila[i]);
            sign = _getSign(fila[i]);
        }
    }

    times.resize(timesQtd + 1);

    return times;
}

int quantosTimes(const Fila &fila) {
    auto times = _getTimes(fila);
    int cont = 0;

    for (auto time : times)
        if (time.size() >= 2)
            cont++;
    
    return cont;
}

Fila maiorTime(const Fila &fila) {
    auto times = _getTimes(fila);
    int maior = 0;

    for (int i = 0; i < times.size(); i++) {
        if (times[i].size() > times[maior].size()) maior = i;
    }

    return times[maior];
}

int semTime(const Fila &fila) {
    auto times = _getTimes(fila);
    int cont = 0;

    for (auto time : times) {
        if (time.size() == 1) cont++;
    }

    return cont;
}

#endif