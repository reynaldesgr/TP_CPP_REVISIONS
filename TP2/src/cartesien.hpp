#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include <cmath>
#include <sstream>

#include <point.hpp>
#include <polaire.hpp>

class Point;
class Polaire;

class Cartesien : public Point
{
    double x;
    double y;

    public:
        Cartesien(): x(0.0), y(0.0){}
        Cartesien(double x, double y): x(x), y(y){}
        Cartesien(const Polaire& p);
        
        const double& getX() const { return x; }
        void       setX(double ix)  { x = ix; }
        const double& getY() const { return y; }
        void       setY(double iy)  { y = iy; }

        void convertir(Point& point) const override;

        void afficher(std::ostream& stream) const override;


        Cartesien * operator=(const Cartesien * c)
        {
            x = c->x;
            y = c->y;
            return this;
        }

        virtual ~Cartesien() {}
};
#endif //CARTESIEN_HPP