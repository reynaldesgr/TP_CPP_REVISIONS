#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

#include <algorithm>

class Echantillon {
    std::vector<Valeur *> elts;

    public:
        void ajouter(double elt) { elts.push_back(new Valeur(elt));}
        size_t getTaille() const { return elts.size(); }
        const Valeur& getMinimum() const { 
            if (elts.empty()){
                throw std::domain_error("error");
            }
            return *(*std::min_element(elts.begin(), elts.end(), 
                [](Valeur * v1, Valeur * v2) { return v1->getNombre() < v2->getNombre(); })); 
        }
        const Valeur& getMaximum() const { 
            if (elts.empty()){
                throw std::domain_error("error");
            }
            return *(*std::max_element(elts.begin(), elts.end(),
                [](Valeur * v1, Valeur * v2) { return v1->getNombre() < v2->getNombre(); })); 
        }

        const Valeur& getValeur(unsigned int index) {
            if (index == elts.size()){
                throw std::out_of_range("error");
            }
            return *elts[index];
        }


        using iterator = std::vector<Valeur *>::iterator;
        using const_iterator = std::vector<Valeur *>::const_iterator;

        iterator begin(){ return elts.begin(); }
        iterator end() { return elts.end(); }
        const_iterator begin() const { return elts.cbegin(); }
        const_iterator end() const { return elts.cend(); }
};
#endif //ECHANTILLON_HPP