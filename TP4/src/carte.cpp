#include <carte.hpp>

std::ostream& operator<<(std::ostream& os, const Carte& carte) {
    os << carte.getValeur();
    return os;
}


int Carte::compteur_ = 0;