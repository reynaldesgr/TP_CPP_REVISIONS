#ifndef ITEM_HPP
#define ITEM_HPP

class Fabricant;

class Item {
    std::string nom;
    int prix;
    Fabricant * fabricant;

    public: 
        Item(std::string in): nom(in), prix(0) {}
        Item(std::string in, int inp): nom(in), prix(inp) {}

        virtual const std::string getNom() const { return nom; }
        void setNom(std::string in) { nom = in; }

        const int& getPrix() const { return prix; }
        void setPrix(int inp) { prix = inp; }

        const Fabricant * getFabricant() const { return fabricant; }
        void setFabricant(Fabricant * f) { fabricant = f; }

        bool estVendable() const { return prix > 0; }

        virtual ~Item(){}
};
#endif //ITEM_HPP