#ifndef _SALLETP_H_
#define _SALLETP_H_
#include "Salle.h"
class Salle_tp : public Salle
{
	private:
		int nb_machines_; //Nombre de machine de la salle de tp
		
	public:
		/*
		* Constructeur
		* Pré-condition : les capacités sont entières et positives (ou nulles)
		*/
		Salle_tp(const int &numero, const int &capacite,const int & nbmachine);
		
		/*
		* Vérifie la capacité de la salle en prenant en compte le nombre de machine
		*/
		bool verifier_capacite(const int & nb_eleves) const;
		
		/*
		* Permet de redéfinir le nombre de machine de la salle après création
		* 0 si paramètre négatif
		*/
		void set_nb_machines(const int & nbmachine);
		
		/*
		* Récupère le nombre de pc de la salle
		*/
		int get_nb_machines() const;
};
#endif
