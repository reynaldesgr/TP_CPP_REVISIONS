#include <cartesien.hpp>

#include <iostream>
#include <typeinfo>

Cartesien::Cartesien(const Polaire& p) {
    x = p.getDistance() * cos(p.getAngle() * M_PI / 180); 
    y = p.getDistance() * sin(p.getAngle() * M_PI / 180);
}

void Cartesien::afficher(std::ostream& stream) const
{
    stream << "(x=" << getX() << ";y=" << getY() << ")";
}

void Cartesien::convertir(Point& point) const {
    if (Polaire * p = dynamic_cast<Polaire *>(&point)) {
        double angle = atan2(y, x) * 180 / M_PI;
        double distance = sqrt(x * x + y * y);
        p->setAngle(angle);
        p->setDistance(distance);
    } else if (Cartesien * c = dynamic_cast<Cartesien *>(&point)) {
        c->setX(getX());
        c->setY(getY());
    }
}