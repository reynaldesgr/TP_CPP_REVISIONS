#ifndef PERIPHERAL_HPP
#define PERIPHERAL_HPP

#include <set>
#include <algorithm>
#include <type_traits>

template <typename T>
class Peripheral {
    public: 
        std::string peripheric;
        T status;

    public:
        Peripheral(std::string p, T s): peripheric(p), status(s){} 
        Peripheral(const Peripheral& p): peripheric(p.peripheric), status(p.status){} 
        Peripheral& operator=(const Peripheral&& p) 
        {
            if (this != &p) 
            {
                peripheric = std::move(p.peripheric);
                status = p.status;

                p.peripheric = nullptr;             
            } 

            return *this;
        } 
}; 


template <typename T>
bool operator<(const Peripheral<T> p1, const Peripheral<T> p2)
{
    return p1.peripheric < p2.peripheric;
} 

template <typename P>
class System {
    std::multiset<P> peripherics;
    public:
        void addPeripheral(P peripheric)
        {
            peripherics.insert(peripheric);
        } 

        template <typename U = P, typename = std::enable_if_t<std::is_same<U, Peripheral<std::string>>::value>>
        bool searchPeripheral(const std::string& name)
        {
            return std::find_if(peripherics.begin(), peripherics.end(),
            [name](P peripheric){
                return peripheric.peripheric == name;
            }) != peripherics.end() ? true : false;
        } 
}; 

template <typename T>
bool checkStatusType(Peripheral<T> p)
{
    if(!std::is_same<T, std::string>()){
        throw std::domain_error("");
    } 
    return true;
}


template <typename T>
struct CheckPeripheralStatus
{
    bool operator()(Peripheral<T> p)
    {
        return std::is_same<T, std::string>() && p.status == "On" ? true : false;
    } 
};

#endif //PERIPHERAL_HPP

