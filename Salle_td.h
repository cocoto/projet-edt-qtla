#ifndef _SALLETD_H_
#define _SALLETD_H_
#include "Salle.h"
class Salle_td : public Salle
{
	private:
		bool videoprojecteur_; //Présence ou non d'un vidéoprojecteur
		
	public:
		/*
		* Constructeur
		* Pré-condition : les capacités sont entières et positives (ou nulles)
		*/
		Salle_td(const int &numero, const int &capacite,const bool & videoprojecteur);
		Salle_td(const int &numero, const int &capacite);
				
		/*
		*Met à jour la présence d'un vidéoprojecteur dans la salle
		*/
		void set_projecteur(const bool & video);
		
		/*
		* Récupère les information de vidéoprojection
		*/
		bool get_videoprojecteur() const;
};
#endif
