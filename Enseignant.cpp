#include "Enseignant.h"

Enseignant::Enseignant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no):Personne(n , p, ap , am),no_enseignant_(no)
{
}

int Enseignant::get_no_enseignant() const
{
    return no_enseignant_;
}

bool Enseignant::operator<(const Enseignant &b) const{
    return no_enseignant_<b.no_enseignant_;
}
