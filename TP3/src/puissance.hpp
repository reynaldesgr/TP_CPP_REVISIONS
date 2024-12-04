#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP

template <unsigned int N>
struct Puissance {
    static double valeur(double x) {
        return x * Puissance<N - 1>::valeur(x);
    }
};

template <>
struct Puissance<0> {
    static double valeur(double x) {
        return 1.0;
    }
};
#endif