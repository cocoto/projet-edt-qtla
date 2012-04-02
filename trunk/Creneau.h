#ifndef _CRENEAU_H_
#define _CRENEAU_H_
#include "Salle.h"
#include "Module.h"
#include "Date.h"
#include "Groupe.h"
class Module;
class Groupe;

class Creneau
{
	private :
		float duree_;
		int heure_;
		Salle* salle_;
        Module*  module_;
		Date* date_;
		Groupe* groupe_;
	public :
		//Constructeurs
        Creneau(Salle *salle,Module *module,Date *date,Groupe *groupe, const float &duree,const int &heure);
		//Fonctions propres
		bool verifier_capacite() const;
		
		//Fonction de comparaison
        bool operator==(const Creneau &creneau2) const;
        bool operator!=(const Creneau &creneau2) const;
        bool operator<(const Creneau &creneau2) const; //Nécéssaire pour l'utilisation de set<Creneau> trie selon Date puis Salle

    //Getters et Setters
         Date* getDate() const;
		float getDuree() const;
        Groupe* getGroupe() const;
		int getHeure() const;
        Module* getModule() const;
        Salle* getSalle() const;
		void setDate(Date *date_);
		void setDuree(float duree_);
		void setGroupe(Groupe *groupe_);
		void setHeure(int heure_);
		void setModule(Module *module_);
		void setSalle(Salle *salle_);
};
#endif
