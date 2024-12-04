#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

class Etudiant {
    std::string nom;
    double note;

    public: 
        const double& getNom() const { return nom; }
};
#endif //ETUDIANT_HPP