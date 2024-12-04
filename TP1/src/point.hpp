#ifndef POINT_HPP
#define POINT_HPP

#include <typeinfo> 

class Point {
    public:
        virtual void afficher(std::ostream& stream) const = 0; 

        virtual void convertir(Point& point) const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Point& c){
            c.afficher(os);
            return os;
        }

        virtual ~Point() = default;
};

#endif //POINT_HPP