#ifndef ARME_HPP
#define ARME_HPP

#include <item.hpp>
#include <enchantement.hpp>

#include <iostream>
#include <stdexcept>

class Item;
class Enchantement;

class Arme : public Item 
{
    int durabilite; 
    const Enchantement * enchantement;

    public:
        Arme(std::string in): Item(in), durabilite(0), enchantement(nullptr) {}
        Arme(std::string in, int inp): Item(in, inp), durabilite(0), enchantement(nullptr) {}
        Arme(std::string in, int inp, int ind): Item(in, inp), durabilite(ind), enchantement(nullptr) {}
        Arme(const Arme& a) : Item(a.getNom(), a.getPrix()){
            durabilite = a.durabilite;
            if (a.enchantement) {
                enchantement = new Enchantement(a.enchantement->getPuissance());
            } else {
                enchantement = nullptr;
            }
        }

        Arme(Arme&& a) : Item(a.Item::getNom(), a.getPrix()), durabilite(a.durabilite), enchantement(a.getEnchantement()) {
            a.enchantement = nullptr;
        }

        Arme& operator=(Arme&& a) {
           
            setNom(a.getNom());
            setPrix(a.getPrix());

            durabilite = a.durabilite;
            enchantement = a.getEnchantement();

            a.enchantement = nullptr;
            
            return *this;
        }


        void utiliser() 
        {
            if (durabilite > 0)
            {
                durabilite--;
                std::cout << durabilite << std::endl;
            } else {
                throw DestroyedItemException("Arme cannot be used (no more durability..)");
            }
        }

        void enchanter(Enchantement * e){
            enchantement = e;
        }

        const std::string getNom() const override {
            return Item::getNom() + " [" + std::to_string(durabilite) + "]";
        }

        const Enchantement * getEnchantement() const {
            return enchantement;
        }

        class DestroyedItemException : public std::exception {
            std::string msg;
            public:
                DestroyedItemException(std::string m): msg(m) {}
                const char * what() const noexcept override {
                    return msg.c_str();
                }
        };

};
#endif //ARME_HPP