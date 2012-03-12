#include "Module.h"

Module::Module(const std::string & Code,const std::string & Titre,const int & NombreCM,const int & NombreTD,const int & NombreTP):
	NombreCM_(NombreCM),NombreTD_(NombreTD),NombreTP_(NombreTP),NombreCTD_(NombreCTD)
{}

Module::Module(const std::string & Code,const std::string & Titre,const int & NombreCTD,const int & NombreTP)
	NombreCM_(0),NombreTD_(0),NombreTP_(NombreTP),NombreCTD_(NombreCTD)
{}


bool Module::est_complet(const liste_creneau & tab_creneau, const Groupe & grp)
{
	bool val_retour; //Booléen de retour de fonction
	int i=0;		//Parcours du tableau de créneaux
	float res=0.0;	//Total des heures effectuées par le groupe dans le module
	for(i=0;i<tab_creneau.size();i++)
	{
		if(tab_creneau[i]->get_groupe()==grp && tab_creneau[i]->get-module()==this)
		{
			res+=tab_creneau[i]->get_duree(); //Augmentation du nombre d'heures effectuées
		}
	}
	
	//Traitement du cas CTD où les heures de cours sont déclarées comme des TD
	if(NombreCTD_ > 0 && grp->get_type()==TD)
	{
		val_retour=res >=NombreCTD_;
	}
	else
	{
		//Traitement de chaque cas
		switch(grp->get_type())
		{
			case 1:
				val_retour= res >= NombreCM_;
				break;
			case 2:
				val_retour= res >= NombreTD_;
				break;
			case 3:
				val_retour= res >= NombreTP_;
				break;
		}
	}
	return val_retour;
}
