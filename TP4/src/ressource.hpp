#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

class Ressource {
    int stock;

    public:
        Ressource(int s): stock(s){}

        void consommer(int conso){
            if (conso < stock) {
                stock -= conso;
            } else {
                stock = 0;
            }
        }

        const int& getStock() const { return stock; }
};
#endif //RESSOURCE_HPP