#include "Salle_tp.h"

Salle_tp::Salle_tp(const int &numero, const int &capacite,const int & nbmachine):Salle(numero,capacite),nb_machines_(nbmachine)
{
}

//Réimplémente la méthode de Salle en prenant en compte le nombre de machine 
//@RAPPORT : choix effectué : nb_eleves = nb_machines *2
bool Salle_tp::verifier_capacite(const int & nb_eleves) const
{
	return nb_eleves<= capacite_ && (nb_eleves*2) <= nb_machines_ ;
}

//Permet de redéfinir le nombre de machine de la salle après création
void Salle_tp::set_nb_machines(const int & nbmachine)
{
	if(nbmachine>0)
	{
		nb_machines_=nbmachine;
	}
	else
	{
		nb_machines_=0;
	}
}

int Salle_tp::get_nb_machines() const
{
	return nb_machines_;
}
