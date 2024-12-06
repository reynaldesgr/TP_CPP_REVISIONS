#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template <typename... T>
class Product {
    public:
        std::string      name;
        double           price;
        int              quantity;
        std::tuple<T...> categories;

    public:
        Product() : name(""), price(0.0), quantity(0), categories() {}

        Product(std::string n, double p, int q, T... category) {
            if (p < 0)
            {
                throw std::invalid_argument("invalid price.");
            }

            if (q < 0)
            {
                throw std::invalid_argument("invalid quantity");
            }

            name = n;
            price = p;
            quantity = q;
            categories = std::make_tuple(category...);
        }

        void printCategories() const
        {
          
        }

    private: 
        template<typename...Args>
        void printElt(const Args&... args)
        {
            ((std::cout << args << std::endl), ...); // Fold expression pour imprimer chaque élément
        }

        template <typename Tuple, std::size_t ...Is>
        void printImpl(const Tuple& t, std::index_sequence<Is...>)
        {
            printElt(std::get<Is>(t)...);  // Accès aux éléments du tuple avec std::get<Is>
        }

        template <typename... Args>
        void printImpl(std::tuple<Args...>& tuple)
        {
            printImpl(tuple, std::index_sequence_for<Args...>()); // Crée la séquence d'indices et appelle printImpl
        }
    
};
#endif //PRODUCT_HPP