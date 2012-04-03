#include "Module.h"

Module::Module(const std::string & Code,const std::string & Titre,const int & NombreCM,const int & NombreTD,const int & NombreTP,Enseignant *ens):
    Code_(Code),Titre_(Titre),NombreCM_(NombreCM),NombreTD_(NombreTD),NombreTP_(NombreTP),NombreCTD_(0),responsable_(ens)
{}

Module::Module(const std::string & Code,const std::string & Titre,const int & NombreCTD,const int & NombreTP,Enseignant* ens)
    :Code_(Code),Titre_(Titre),NombreCM_(0),NombreTD_(0),NombreTP_(NombreTP),NombreCTD_(NombreCTD),responsable_(ens)
{}
std::string Module::get_Code() const{
    return Code_;
}

bool Module::est_complet(const liste_creneau & tab_creneau, Groupe *grp)
{
	bool val_retour; //Booléen de retour de fonction
    float res=0.0;	//Total des heures effectuées par le groupe dans le module
    liste_creneau::iterator i;
    for(i=tab_creneau.begin();i!=tab_creneau.end();i++)
	{
        if((*i).getGroupe()==grp && (*i).getModule()==this)
		{
            res+=(*i).getDuree(); //Augmentation du nombre d'heures effectuées
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
            case CM:
				val_retour= res >= NombreCM_;
				break;
            case TD:
				val_retour= res >= NombreTD_;
				break;
            case TP:
				val_retour= res >= NombreTP_;
				break;
		}
	}
	return val_retour;
}

bool Module::operator<(const Module &m2) const{
    return Code_<m2.Code_;
}

Enseignant* Module::get_responsable() const{
    return responsable_;
}
