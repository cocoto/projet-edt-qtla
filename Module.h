#ifndef _MODULE_H_
#define _MODULE_H_
#include <iostream>
#include "Groupe.h"
#include "Enseignant.h"
#include "Creneau.h"
#include <vector>
typedef std::vector<Creneau> liste_creneau;
class Module
{
	private:
		int NombreCM_,NombreTD_,NombreTP_,NombreCTD_;
		std::string Code_,Titre_;
	public :
		/*
		* Constructeurs
		*/
		Module(const std::string & Code,const std::string & Titre,const int & NombreCM,const int & NombreTD,const int & NombreTP);
		Module(const std::string & Code,const std::string & Titre,const int & NombreCTD,const int & NombreTP);
		
		//Permet de vérifier que le nombre d'heures effectuées par un groupe dans une liste de créneaux corrrespond bien aux modalités du
		//Module. (nb heures supérieur ou égal) Les CTD sont considérés comme des cours de type TD
		bool est_complet(const liste_creneau & tab_creneau, const Groupe & grp);

};

#endif
