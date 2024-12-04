#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <sstream>

#include <exception.hpp>


template <typename... Args>
std::string chaine(const Args&... args);

template <typename... Args>
std::string chaine(std::tuple<Args...>& tuple);

template <typename T>
std::string chaine(T obj){
    throw ExceptionChaine("Conversion en chaine impossible pour '" + demangle(typeid(obj).name()) + "'");
}

template <>
std::string chaine(std::string s)
{
    return s;
}

std::string chaine(int i)
{
    std::stringstream s;
    s << i;
    return s.str();
}

std::string chaine(double d)
{
    return std::to_string(d);
} 


// Variadic template
template <typename F, typename... R>
std::string chaine(F first, R... rest)
{
    std::ostringstream oss;

    oss << chaine(first) << " ";

    ((oss << chaine(rest) << " "), ...);

    return oss.str();
}

template <typename Tuple, std::size_t... Is>
std::string chaine_helper(const Tuple& t, std::index_sequence<Is...>)
{
    return chaine(std::get<Is>(t)...);
}

// Tuples
template <typename...Args>
std::string chaine(const Args&... args)
{
    std::ostringstream oss;
    ((oss << chaine(args) << " "), ...);
    return oss.str();
}

template <typename... Args>
std::string chaine(std::tuple<Args...>& tuple)
{
    return chaine_helper(tuple, std::index_sequence_for<Args...>());
}

#endif //CHAINE_HPP