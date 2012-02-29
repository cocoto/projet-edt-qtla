#ifndef _PERSONNE_H_
#define _PERSONNE_H_
#include <string>

class Personne
{
    public:
        Personne(std::string n , std::string p);
        Personne(std::string n , std::string p, std::string ap , std::string am);
        std::string get_nom();
        std::string get_prenom();
        std::string get_adresse_p();
        std::string get_adresse_m();
        void set_nom(std::string n);
        void set_prenom(std::string p);
        void set_adresse_p(std::string ap);
        void set_adresse_m(std::string am);
    private:
        std::string nom_;
        std::string prenom_;
        std::string adresse_p_;
        std::string adresse_m_;
};

#endif
