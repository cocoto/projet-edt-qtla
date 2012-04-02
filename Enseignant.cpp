#include "Enseignant.h"

Enseignant::Enseignant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no):Personne(n , p, ap , am),no_enseignant_(no)
{
}

int Enseignant::get_no_enseignant() const
{
    return no_enseignant_;
}
