#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include "Personne.h"
class Enseignant: public Personne
{
private:
    int no_enseignant_;
public:
    Enseignant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no);
    int get_no_enseignant() const;
    bool operator<(const Enseignant &b) const;
};

#endif // ENSEIGNANT_H
