#include "Etudiant.h"

Etudiant::Etudiant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no):Personne(n , p, ap , am)
{
    no_eleve_ = no;
}
int Etudiant::get_no_eleve() const
{
    return no_eleve_;
}
bool Etudiant::operator<(const Etudiant &e2) const{
    no_eleve_<e2.no_eleve_;
}
bool Etudiant::operator==(const Etudiant &e2) const{
    no_eleve_==e2.no_eleve_;
}
