#ifndef _ETUDIANT_H_
#define _ETUDIANT_H_
#include "personne.h"
#include <vector>
class Etudiant : public Personne
{
    private:
        int no_eleve_;
    public:
        Etudiant(std::string n , std::string p, std::string ap , std::string am, int no);
        std::vector<Groupe> liste_groupe(std::vector<Group> liste);
};


#endif
