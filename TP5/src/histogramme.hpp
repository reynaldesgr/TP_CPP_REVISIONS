#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <valeur.hpp>
#include <echantillon.hpp>
#include <classe.hpp>

#include <iostream>

#include <map>
#include <set>

template <typename Comparator = std::less<Classe>>
class Histogramme {

    double borneSup;
    double borneInf;

    double nbClasses;

    std::set<Classe, Comparator> classes;
    std::multimap<Classe, Valeur, Comparator> classesMultiMap;

    public:
        Histogramme(double n, double a, double b): borneSup(a), borneInf(b), nbClasses(n) {
            double pas = (borneSup - borneInf) / nbClasses;
            for (int i = borneInf; i < borneSup; i+=pas)
            {
                classes.insert(Classe(i, i + pas));
            }
        }

        double getBorneInf() const { return borneInf; }
        double getBorneSup() const { return borneSup; }
        unsigned getNbClasses() const { return nbClasses; }

        template <typename OtherComparator>
        Histogramme(const Histogramme<OtherComparator>& other)
            : borneInf(other.getBorneInf()), borneSup(other.getBorneSup()), nbClasses(other.getNbClasses()) {
            for (const auto& c : other.getClasses()) {
                classes.insert(c);
            }
        }


        void ajouter(const Valeur& v) {
            auto it = std::find_if(classes.begin(), classes.end(),
            [v](const Classe& c) {
                double nb = v.getNombre();
                return nb >= c.getBorneInf() && nb < c.getBorneSup();
            });

            if (it != classes.end()){
                Classe c = *it;
                c.ajouter();
                classes.erase(*it);
                classes.insert(c);
                classesMultiMap.emplace(c, v);
            }
        }

        void ajouter(const Echantillon& e) {
            for (Valeur * v : e)
            {
                ajouter(*v);
            }
        }

        const std::set<Classe, Comparator>& getClasses() const { return classes; }

        const std::vector<std::pair<const Classe, Valeur>> getValeurs() const {
            std::vector<std::pair<const Classe, Valeur>> valeurs;
            for (const auto& pair : classesMultiMap) {
                valeurs.push_back(pair);
            }
            return valeurs;
        }

        const auto getValeurs(const Classe& classe) const
        {
            return classesMultiMap.equal_range(classe);
        }

};

class ComparateurQuantite {
    public:
        bool operator()(const Classe& c1, const Classe& c2) const
        {
            bool isEqual = c1.getQuantite() == c2.getQuantite();
            return isEqual ? c1.getBorneInf() < c2.getBorneInf() : c1.getQuantite() > c2.getQuantite();
        }
};
#endif //HISTOGRAMME_HPP