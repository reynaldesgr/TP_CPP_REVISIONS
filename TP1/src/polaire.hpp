#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include <cmath>
#include <sstream>

#include <point.hpp>
#include <cartesien.hpp>

class Point;
class Cartesien;

class Polaire : public Point {
    double angle;
    double distance;

    public:
        Polaire(): angle(0.0), distance(0.0) {}
        Polaire(double a, double d): angle(a), distance(d) {}
        Polaire(const Cartesien& c);
        
        const double& getAngle() const { return angle; }
        void          setAngle(const double& a) { angle = a; }

        const double& getDistance() const { return distance; }
        void          setDistance(const double& d) { distance =  d; }
        void          afficher(std::ostream& stream) const override;

        void convertir(Point& point) const override;
};
#endif // POLAIRE_HPP