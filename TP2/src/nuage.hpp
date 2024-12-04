#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <point.hpp>
#include <cstddef>
#include <cartesien.hpp>
#include <iostream>

template <typename T>
class Nuage {
    std::vector<T> points;

    public:
    using value_type = T;
        void ajouter(const T& p){ points.push_back(p); }

        size_t size() const { return points.size(); }
        
        using iterator = typename std::vector<T>::iterator;
        using const_iterator =  typename std::vector<T>::const_iterator;

        const std::vector<T>& getPoints() const { return points; }

        iterator begin() { return points.begin(); }
        iterator end() { return points.end(); }
        const_iterator begin() const { return points.cbegin(); }
        const_iterator end() const { return points.cend(); }

        ~Nuage() {}

        const T operator[](size_t index) const
        {
            return  index >= points.size() ? std::out_of_range("error") : points[index];
        }

        bool empty() const {
            return points.empty();
        }

};

template <typename T>
T barycentre_v1(const Nuage<T>& n) {
    double x = 0.0, y = 0.0;

    const auto& points = n.getPoints();

    for (auto point : points) {
        Cartesien* c = dynamic_cast<Cartesien*>(&point);
        if (c) {
            x += c->getX();
            y += c->getY();
        } else {
            Polaire* p = dynamic_cast<Polaire*>(&point);
            if (p) {
                Cartesien cartesien(*p);
                x += cartesien.getX();
                y += cartesien.getY();
            }
        }
    }

    return points.empty() ? Cartesien() : Cartesien(x / points.size(), y / points.size());
}

template <>
Polaire barycentre_v1(const Nuage<Polaire>& n) {
    double angle = 0.0, distance = 0.0;

    const auto& points = n.getPoints();

    for (Polaire point : points) {
        angle += point.getAngle();
        distance += point.getDistance();
    }

    return points.empty() ? Polaire() : Polaire(angle / points.size(), distance / points.size());
}

template <typename C>
auto barycentre_v2(const C& nuage) {
    using T = typename C::value_type;

    if (nuage.empty()) {
        if constexpr (std::is_same<T, Cartesien>::value) {
            return Cartesien(0, 0); // Renvoie (0, 0) pour les coordonnées cartésiennes
        } else if constexpr (std::is_same<T, Polaire>::value) {
            return Polaire(0, 0); // Renvoie (0, 0) pour les coordonnées polaires
        }
    }

    Cartesien sum(0, 0); 
    double nb_points = 0;

    // Itération sur les points dans le conteneur
    for (const T& point : nuage) {
        Cartesien temp; 
        point.convertir(temp);  // Convertir directement le point en Cartesien

        sum.setX(sum.getX() + temp.getX());
        sum.setY(sum.getY() + temp.getY());
        nb_points++;
    }

    // Calcul de la moyenne
    if (nb_points > 0) {
        sum.setX(sum.getX() / nb_points);
        sum.setY(sum.getY() / nb_points); 
    }

    // Retourner le barycentre selon le type
    if constexpr (std::is_same<T, Cartesien>::value) {
        return sum; // Retourne le barycentre en coordonnées cartésiennes
    } 
    else if constexpr (std::is_same<T, Polaire>::value) {
        Polaire barycentre_polaire;
        sum.convertir(barycentre_polaire);  // Convertir le barycentre cartésien en polaire

        return barycentre_polaire; // Retourne le barycentre en coordonnées polaires
    }
}


class BarycentreCartesien {
    public: 
        template <typename T>
        Cartesien operator()(const Nuage<T>& n) const {
            return barycentre(n);
        }
};

class BarycentrePolaire {
    public: 
        template <typename T>
        Polaire operator()(const Nuage<T>& n) const {
            return barycentre(n);
        }
};

#endif // NUAGE_HPP
