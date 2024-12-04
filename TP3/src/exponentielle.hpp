#ifndef EXPONENTIELLE_HPP
#define EXPONENTIELLE_HPP

#include <factorielle.hpp>
#include <puissance.hpp>

template <unsigned int N>
struct Exponentielle {
    static double valeur(double x) {
        return Puissance<N>::valeur(x) / Factorielle<N>::valeur + Exponentielle<N - 1>::valeur(x);
    }
};

template <>
struct Exponentielle<0> {
    static double valeur(double x) {
        return 1.0;
    }
};

#endif 