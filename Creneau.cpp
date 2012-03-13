#include "Creneau.h"

Creneau::Creneau(const Salle & salle, const Module & module, const Date & date, const Groupe & groupe, const float & duree, const int & heure)
{
	//Constructeur écrit sous cette forme pour plus de simplicité
	duree_=duree;
	heure_=heure;
	salle_=salle;
	module_=module;
	date_=date;
	groupe_=groupe;
}


bool Creneau::operator !=(const Creneau & creneau1, const Creneau & creneau2) const
{
	return !(creneau1==creneau2);
}


//On trie les Creneau par date puis heure puis salle.
//Un créneau se déroulant dans la même salle à la même heure le même jour est impossible
bool Creneau::operator <(const Creneau & creneau1, const Creneau & creneau2) const
{
	if(creneau1.getDate()!=creneau2.getDate())
	{
		return creneau1.getDate()<creneau2.getDate();
	}
	else if(creneau1.getHeure()!=creneau2.getHeure()){
		return creneau1.getHeure<creneau2.getHeure;
	}
	else return creneau1.getSalle()<creneau2.getSalle();
}



bool Creneau::verifier_capacite() const
{
	return getSalle()->verifier_capacite(getGroupe()->nb_etu());
}


//On considère qu'un seul créneau se déroule dans une salle donnée, un jour donné et une heure donnée
bool Creneau::operator ==(const Creneau & creneau1, const Creneau & creneau2) const
{
	return  creneau1.getDate()==creneau2.getDate() &&
			creneau1.getHeure()==creneau2.getHeure() &&
			creneau1.getSalle()==creneau2.getSalle();
}

Date *Creneau::getDate() const
{
    return date_;
}

float Creneau::getDuree() const
{
    return duree_;
}

Groupe *Creneau::getGroupe() const
{
    return groupe_;
}

int Creneau::getHeure() const
{
    return heure_;
}

Module *Creneau::getModule() const
{
    return module_;
}

Salle *Creneau::getSalle() const
{
    return salle_;
}

void Creneau::setDate(Date *date_)
{
    this->date_ = date_;
}

void Creneau::setDuree(float duree_)
{
    this->duree_ = duree_;
}

void Creneau::setGroupe(Groupe *groupe_)
{
    this->groupe_ = groupe_;
}

void Creneau::setHeure(int heure_)
{
    this->heure_ = heure_;
}

void Creneau::setModule(Module *module_)
{
    this->module_ = module_;
}

void Creneau::setSalle(Salle *salle_)
{
    this->salle_ = salle_;
}
