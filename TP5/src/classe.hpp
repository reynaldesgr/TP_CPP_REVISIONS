#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe {
    double borneInf;
    double borneSup;

    int quantite;

    public:
        Classe(double a, double b): borneInf(a), borneSup(b), quantite(0) {}

        const double& getBorneInf() const { return borneInf; }
        void setBorneInf(double a) { borneInf = a; }

        const double& getBorneSup() const { return borneSup; }
        void setBorneSup(double b) { borneSup = b; }

        const int& getQuantite() const { return quantite; }
        void setQuantite(int q) { quantite = q; }


        bool operator<(const Classe& other) const {
            return borneInf < other.borneInf;
        }

        bool operator>(const Classe& other) const {
            return borneSup > other.borneSup;
        }

        void ajouter(){ quantite++; }
};
#endif //CLASSE_HPP