#include "etudiant.h"

Etudiant::Etudiant(std::string n , std::string p, std::string ap , std::string am, int no):Personne(n , p, ap , am)
{
    no_eleve_ = no;
}

std::vector<Groupe> Etudiant::liste_groupe(std::vector<Groupe> liste)
{   int i = 0;
    while(i<liste.size())
    {
        if(liste.at(i).contient_etu(no_eleve_))
        {
            i++;
        }else
        {
            liste.erase(liste.begin()+i);
        }
    }
}
