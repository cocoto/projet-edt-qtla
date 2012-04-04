#include "Salle.h"

Salle::Salle(const int &numero, const int &capacite):numero_(numero),capacite_(capacite)
{
}

int Salle::get_capacite() const
{
	return capacite_;
}
int Salle::get_numero() const
{
	return numero_;
}
bool Salle::verifier_capacite(const int & nb_eleve) const
{
	return nb_eleve <= capacite_;
}
bool Salle::operator <(const Salle &b) const
{
    return get_numero()<b.get_numero();
}

Salle::~Salle()
{
}

bool Salle::operator==(const Salle &s2){
    return numero_==s2.numero_;
}

void Salle::set_capacite(const int &capacite) const{
    capacite_=capacite;
}
