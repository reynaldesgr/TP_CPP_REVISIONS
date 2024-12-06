#ifndef INVENTAIRE_HPP
#define INVENTAIRE_HPP

#include <set> 
#include <map>
#include <vector>


template <typename Comparator>
class Inventaire {
    std::set<Item *, Comparator> items;

    public :

    enum Categorie {
        ARME = 'A',
        CONSOMMABLE = 'C',
        NORMAL = 'N',
        RARE = 'R'
    };

    using map_t = std::multimap<Categorie, Item *>;
    using list_t = std::set<Item *, Comparator>;

    private: 

        map_t itemsParCategorie;
        list_t itemsRares;
        list_t itemsNormaux;
        list_t itemsArmes;
        list_t itemsConsommables;

    public:

    void ajouter(Item * item){
        items.insert(item);
        if (dynamic_cast<Arme *>(item)){
            itemsArmes.insert(item);
        } else {
            itemsNormaux.insert(item);
        }
    }

    void ajouter(Item * item, Categorie categorie)
    {
        items.insert(item);
        itemsParCategorie.emplace(categorie, item);
        switch(categorie) {
            case Categorie::ARME :
                itemsArmes.insert(item);
                break;
            case Categorie::CONSOMMABLE :
                itemsConsommables.insert(item);
                break;
            case Categorie::NORMAL :
                itemsNormaux.insert(item);
                break;
            case Categorie::RARE :
                itemsRares.insert(item);
                break;
            default:
                break;
        }
    }

    list_t& getItemsParCategorie(Categorie cat){
         switch(cat) {
            case Categorie::ARME :
                return itemsArmes;
                break;
            case Categorie::CONSOMMABLE :
               return itemsConsommables;
                break;
            case Categorie::NORMAL :
                return itemsNormaux;
                break;
            case Categorie::RARE :
                return itemsRares;
                break;
            default:
                return itemsNormaux;
                break;
        }
    }
    size_t getTaille() const { return items.size(); }
};


class TrieurAlphabetique {
    public:
        bool operator()(const Item * i1, const Item * i2) const
        {
            return i1->getNom() < i2->getNom();
        }
};

class TrieurPrix {
    public:
        bool operator()(const Item * i1, const Item * i2) const
        {
            return i1->getPrix() < i2->getPrix();
        }
};
#endif // INVENTAIRE_HPP