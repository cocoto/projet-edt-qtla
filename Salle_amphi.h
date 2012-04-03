#ifndef _SALLEAMPHI_H_
#define _SALLEAMPHI_H_
#include "Salle.h"
class Salle_amphi : public Salle
{
	private:
		bool visio_conference_; //Présence ou non d'un système de visio
		
	public:
		/*
		* Constructeur
		* Pré-condition : les capacités sont entières et positives (ou nulles)
		*/
		Salle_amphi(const int &numero, const int &capacite,const bool & visio);
		Salle_amphi(const int &numero, const int &capacite); //Par défaut un 
        bool verifier_type(const Type_salle &type) const;
		/*
		* Met à jour la présence d'une visio
		*/
		void set_visio(const bool & visio);
		
		/*
		* Récupère les information de visio
		*/
		bool get_visio() const;
};
#endif
