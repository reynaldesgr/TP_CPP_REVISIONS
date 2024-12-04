#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <point.hpp>
#include <iostream>

class Nuage {
    std::vector<Point*> points;

    public:
        void ajouter(Cartesien& c) { points.push_back(new Cartesien(c)); }
        void ajouter(Polaire& p) { points.push_back(new Polaire(p)); }
        size_t size() const { return points.size(); }
        
        using iterator = std::vector<Point*>::iterator;
        using const_iterator = std::vector<Point*>::const_iterator;

        const std::vector<Point*>& getPoints() const { return points; }

        iterator begin() { return points.begin(); }
        iterator end() { return points.end(); }
        const_iterator begin() const { return points.cbegin(); }
        const_iterator end() const { return points.cend(); }

        ~Nuage() {
            for (auto point : points) {
                delete point;
            }
        }
};

Cartesien barycentre(const Nuage& n) {
    double x = 0.0, y = 0.0;

    const auto& points = n.getPoints();

    for (auto point : points) {
        Cartesien* c = dynamic_cast<Cartesien*>(point);
        if (c) {
            x += c->getX();
            y += c->getY();
        } else {
            Polaire* p = dynamic_cast<Polaire*>(point);
            if (p) {
                Cartesien cartesien(*p);
                x += cartesien.getX();
                y += cartesien.getY();
            }
        }
    }

    return Cartesien(x / points.size(), y / points.size());
}

class BarycentreCartesien {
    public: 
        Cartesien operator()(const Nuage& n) const {
            return barycentre(n);
        }
};

class BarycentrePolaire {
    public: 
        Polaire operator()(const Nuage& n) const {
            return barycentre(n);
        }
};

#endif // NUAGE_HPP
