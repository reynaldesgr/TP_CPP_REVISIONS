#include <polaire.hpp>

#include <cmath>
#include <iostream>
#include <typeinfo>
#include <iostream>

Polaire::Polaire(const Cartesien& c) {
    double x = c.getX();
    double y = c.getY();
        
    angle = atan2(y, x) * 180 / M_PI;
    distance = sqrt(x * x + y * y);
}

void Polaire::afficher(std::ostream& stream) const
{
    stream << "(a=" << getAngle() << ";d=" << getDistance() << ")";
}

void Polaire::convertir(Point& point) const {
    if (Cartesien *c = dynamic_cast<Cartesien*>(&point)) {
        double x = distance * cos(angle * M_PI / 180); 
        double y = distance * sin(angle * M_PI / 180);
        c->setX(x);
        c->setY(y);
    } 
    else if (Polaire * p = dynamic_cast<Polaire *>(&point))
    {
        p->setAngle(getAngle());
        p->setDistance(getDistance());
    }
}