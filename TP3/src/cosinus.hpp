#ifndef COSINUS_HPP
#define COSINUS_HPP

#include <exponentielle.hpp>
#include <factorielle.hpp>
#include <puissance.hpp>

// Cosinus
template <unsigned int N>
struct Cosinus {
    static double valeur(double x) {
        return ((N % 2 == 0) ? 1 : -1) * Puissance<2 * N>::valeur(x) / Factorielle<2 * N>::valeur + Cosinus<N - 1>::valeur(x);
    }
};

template <>
struct Cosinus<0> {
    static double valeur(double x) {
        return 1.0;
    }
};

// Sinus
template <unsigned int N>
struct Sinus {
    static double valeur(double x) {
        return ((N % 2 == 0) ? 1 : -1) * Puissance<2 * N + 1>::valeur(x) / Factorielle<2 * N + 1>::valeur + Sinus<N - 1>::valeur(x);
    }
};

template <>
struct Sinus<0> {
    static double valeur(double x) {
        return x;
    }
};

#endif