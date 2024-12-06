#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <map>

template <typename P>
class Store {
    public:
        std::string name;
        std::map<std::string, P> products;

        Store(std::string n): name(n) {}

        void addProduct(P& product) {
            if (products.find(product.name) == products.end()){
                products.insert(std::make_pair(product.name, product));
            }else{
                products[product.name].quantity += product.quantity;
            }
        }

        bool removeProduct(const std::string& productName, int quantityToRemove)
        {
            if (products.find(productName) != products.end())
            {
                if (products[productName].quantity >= quantityToRemove)
                {
                    products[productName].quantity -= quantityToRemove;
                    return true;
                }
            }
            return false;
        }

};
#endif //INVENTORY_HPP