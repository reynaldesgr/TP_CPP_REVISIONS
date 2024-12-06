#ifndef ENCHANTEMENT_HPP
#define ENCHANTEMENT_HPP

class Enchantement {
    double puissance;

    public:
        Enchantement(): puissance(0) {}
        Enchantement(double p): puissance(p){}

        const double& getPuissance() const { return puissance; }

};
#endif //ENCHANTEMENT_HPP