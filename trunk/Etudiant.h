#ifndef _ETUDIANT_H_
#define _ETUDIANT_H_
#include "Personne.h"
class Etudiant : public Personne
{
    private:
        int no_eleve_;
    public:
        Etudiant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no);
        int get_no_eleve() const;
        bool operator<(const Etudiant &e2) const;
};


#endif
