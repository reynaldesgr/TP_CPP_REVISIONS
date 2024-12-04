#ifndef VALEUR_HPP
#define VALEUR_HPP

class Valeur {
    std::string etudiant;
    double a;
    public:
        Valeur(): a(0.0), etudiant("inconnu") {}
        Valeur(double in): a(in) {}
        Valeur(double in, std::string e): a(in), etudiant(e) {}

        const double& getNombre() const { return a; }
        const double& getNote() const { return a; }
        void setNote(double note) { a = note; }
        void setEtudiant(std::string e) { etudiant = e; }

        const std::string& getEtudiant() const { return etudiant; }
        void setNombre(double in) { a = in; }
};
#endif //VALEUR_HPP