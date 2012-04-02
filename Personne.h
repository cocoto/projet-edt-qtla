#ifndef _PERSONNE_H_
#define _PERSONNE_H_
#include <string>

class Personne
{
    public:
        Personne(const std::string &n ,const std::string &p);
        Personne(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am);
        std::string get_nom() const;
        std::string get_prenom() const;
        std::string get_adresse_p() const;
        std::string get_adresse_m() const;
        void set_nom(const std::string &n);
        void set_prenom(const std::string &p);
        void set_adresse_p(const std::string &ap);
        void set_adresse_m(const std::string &am);
    private:
        std::string nom_;
        std::string prenom_;
        std::string adresse_p_;
        std::string adresse_m_;
};

#endif
