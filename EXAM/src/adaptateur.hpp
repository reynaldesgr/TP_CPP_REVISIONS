#ifndef ADAPTATEUR_HPP
#define ADAPTATEUR_HPP

#include <iostream>

template <typename T>
class Adaptateur {
    T * obj;

    public:
        Adaptateur(T& o): obj(&o) {}
        
        void activer(){
            Arme * a = dynamic_cast<Arme *>(obj);
            if (a != nullptr)
            {
                a->utiliser();
            } 
            else 
            {
                throw std::runtime_error("Cannot activate");
            }
           
        }
};
#endif // ADAPTATEUR_HPP