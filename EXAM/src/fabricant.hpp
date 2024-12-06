#ifndef FABRICANT_HPP
#define FABRICANT_HPP

#include <string>
#include <set>

#include "item.hpp"
class Item;

class Fabricant {
    std::string nom;
    std::set<std::string> nomItems;

    public:
        Fabricant(std::string n): nom(n) {}

        const std::string& getNom() const { return nom; }
        bool hasItemsEnProduction() const { return nomItems.size(); }

        void ajouterProduction(std::string nomItem){
            nomItems.insert(nomItem);
        }

        Item * produire(std::string nomItem)
        {
            auto it = std::find(nomItems.begin(), nomItems.end(), nomItem);

            if (it != nomItems.end()){
                Item * it = new Item("[" + nom + "] " + nomItem);
                it->setFabricant(this);
                return it;
            } else {
                return nullptr;
            }
        }
};
#endif //FABRICANT_HPP