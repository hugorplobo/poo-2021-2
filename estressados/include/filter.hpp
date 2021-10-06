#ifndef FILTER_HPP
#define FILTER_HPP

#include <vector>
#include <algorithm>
#include <functional>

typedef std::vector<int> Fila;

Fila clone(const Fila &fila) {
    Fila result(fila.size());
    std::copy(fila.begin(), fila.end(), result.begin());

    return result;
}

Fila copiarSe(const Fila& fila, std::function<bool (int)> predicate) {
    Fila result(fila.size());
    auto it = std::copy_if(fila.begin(), fila.end(), result.begin(), predicate);
    result.resize(std::distance(result.begin(), it));
    return result;
}

Fila copiarHomens(const Fila &fila) {
    return copiarSe(fila, [](int x) { return x > 0; });
}

Fila copiarCalmos(const Fila &fila) {
    return copiarSe(fila, [](int x) { return std::abs(x) < 10; });
}

Fila copiarMulheresCalmas(const Fila &fila) {
    return copiarSe(fila, [](int x) { return x < 0 && x > -10; });
}

#endif