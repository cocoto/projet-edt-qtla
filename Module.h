#ifndef _MODULE_H_
#define _MODULE_H_
#include <iostream>
#include "Enseignant.h"
#include "Creneau.h"
#include "Groupe.h"
#include <set>
class Creneau;
typedef std::set<Creneau> liste_creneau;
class Module
{
	private:
		int NombreCM_,NombreTD_,NombreTP_,NombreCTD_;
		std::string Code_,Titre_;
        Enseignant* responsable_;
	public :
		/*
		* Constructeurs
		*/
        Module(const std::string & Code,const std::string & Titre,const int & NombreCM,const int & NombreTD,const int & NombreTP,Enseignant *ens);
        Module(const std::string & Code,const std::string & Titre,const int & NombreCTD,const int & NombreTP,Enseignant* ens);
		
		//Permet de vérifier que le nombre d'heures effectuées par un groupe dans une liste de créneaux corrrespond bien aux modalités du
		//Module. (nb heures supérieur ou égal) Les CTD sont considérés comme des cours de type TD
        bool est_complet(const liste_creneau & tab_creneau, Groupe *grp);
        std::string get_Code() const;
        int get_NombreCM() const;
        int get_NombreTD() const;
        int get_NombreTP() const;
        int get_NombreCTD() const;
        Enseignant* get_responsable() const;
        bool operator<(const Module &m2) const;
};

#endif
