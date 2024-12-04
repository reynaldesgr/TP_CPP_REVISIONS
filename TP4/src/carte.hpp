#ifndef carte_hpp
#define carte_hpp

#include <iostream>

#include "usine.hpp"

class UsineCarte;

class Carte {
    int valeur_;
    static int compteur_;

    // Constructeur privé, uniquement accessible via la classe UsineCarte
    explicit  Carte(int v): valeur_(v) { ++compteur_; }
    

    // UsineCarte est une classe amie pour avoir accès au constructeur privé
    friend class UsineCarte;

    public:
        ~Carte() { --compteur_; }

       static int getCompteur() {
            return compteur_; // Retourne le nombre actuel d'instances
        }
        int getValeur() const
        {
            return valeur_;
        }

    // Empêcher affectation + copie
    Carte(const Carte&) = delete;
    Carte& operator=(const Carte&) = delete;
};

std::ostream& operator<<(std::ostream& os, const Carte& carte);

#endif