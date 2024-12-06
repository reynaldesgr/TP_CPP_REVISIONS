#ifndef ORDER_HPP
#define ORDER_HPP

template <typename... T>
class Order {
    public:
        int orderId;
        std::tuple<T...> products;
        std::string status;

        Order(int id, T&... p): orderId(id), products(std::make_tuple(p...)){}

        bool addProduct(const T&... p, int quantityToOrder)
        {
            if (validateQuantity(quantityToOrder, p...)) {
                std::tuple_cat(products, std::make_tuple(p...));  
                return true;
            }
            return false;
        }

        void printProducts() const {
            printProducts(products);
        }

        void cancelOrder()
        {
            status = "canceled";
        }

        void confirmOrder()
        {
            status = "shipped";
        }

        template <typename... Args>
        void printElt(Args... args) const
        {
            ((std::cout << args.name << std::endl), ...);
        }

        template <typename Tuple, std::size_t ... Is>
        void printProducts(Tuple t, std::index_sequence<Is...>) const
        {
            printElt(std::get<Is>(t)...);
        }

        template <typename... Args>
        void printProducts(std::tuple<Args...> tuple) const
        {
            printProducts(tuple, std::index_sequence_for<Args...>());
        }

        template <typename ProductType>
        bool validateQuantity(int quantityToOrder, const ProductType& p) const {
            return p.quantity >= quantityToOrder;
        }
}; 

#endif // ORDER_HPP