#include <usine.hpp>
std::unique_ptr<Carte> UsineCarte::getCarte(){
    // Crée une nouvelle carte avec la valeur courante et incrémente le compteur
    // si >= 52 retourne un pointeur null
    return compteur_ >= nbCartes_ ? nullptr : std::unique_ptr<Carte>(new Carte(compteur_++));; 
}


void remplir(paquet_t& paquet, UsineCarte& usine)
{
    std::unique_ptr<Carte> carte;

    while ((carte = usine.getCarte()) != nullptr)
    {
        // std::move(carte) pour transférer la propriété du pointeur unique dans le vecteur
        // sans le copier, garantissant ainsi que la gestion mémoire reste sûre et sans fuite.
        paquet.push_back(std::move(carte));
    }
}

// Operateur << redefini pour paquet_t
std::ostream& operator<<(std::ostream& os, const paquet_t& paquet)
{
    for (const auto& carte : paquet)
    {
        os << *carte << " ";
    }

    return os;
}