#ifndef CONSOMMATEUR_HPP
#define CONSOMMATEUR_HPP

#include <vector>

#include <ressource.hpp>

class Ressource;

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

class Consommateur {
    std::shared_ptr<Ressource> ressource;
    int conso;

    public:
        Consommateur( int c, std::shared_ptr<Ressource> r): ressource(r), conso(c) {}
        
        void puiser(){ 
            if (ressource)
            {
                ressource->consommer(conso); 
                if (ressource->getStock() == 0)
                {
                    ressource = nullptr;
                }
            }
        }

};

std::ostream& operator<<(std::ostream& os, const ressources_t& ressources)
{
    for (std::vector<std::weak_ptr<Ressource>>::const_iterator it = ressources.begin(); it != ressources.end(); ++it)
    {
        if (std::shared_ptr<Ressource> ressource = it->lock())
        {
            os << ressource->getStock() << " ";
        } else {
            os << "- ";
        }
    }
 
    return os;
}
#endif //CONSOMMATEUR_HPP