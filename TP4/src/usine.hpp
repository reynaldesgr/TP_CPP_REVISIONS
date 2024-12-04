#ifndef usine_carte_hpp
#define usine_carte_hpp

#include <iostream>
#include <memory>
#include <vector>

#include "carte.hpp"

#define DEFAULT_NB_CARTES 52

class Carte;

// Paquet = vecteur de pointeurs uniques sur le type T = Carte
using paquet_t = std::vector<std::unique_ptr<Carte>>;

class UsineCarte {
    int compteur_;
    int nbCartes_;

    public:
        UsineCarte(): compteur_(0), nbCartes_(DEFAULT_NB_CARTES) {}

        UsineCarte(int n){ compteur_ = 0; nbCartes_ = n; }

        // Méthode pour obtenir un pointeur unique vers une nouvelle carte
        std::unique_ptr<Carte> getCarte();

        // Empêcher constructeur de copie + opérateur d'affectation
        UsineCarte(const UsineCarte& usine) = delete;
        UsineCarte& operator=(const UsineCarte& usine) = delete;
};

void remplir(paquet_t& paquet, UsineCarte& usine);

std::ostream& operator<<(std::ostream& os, const paquet_t& paquet);
#endif