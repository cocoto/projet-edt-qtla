#include "Salle_td.h"
		Salle_td::Salle_td(const int &numero, const int &capacite,const bool & videoprojecteur):Salle(numero,capacite),videoprojecteur_(videoprojecteur)
		{
		}
		Salle_td::Salle_td(const int &numero, const int &capacite):Salle(numero,capacite),videoprojecteur_(false)
		{	
		}
				
		void Salle_td::set_projecteur(const bool & video)
		{
			videoprojecteur_=video;
		}
		
		bool Salle_td::get_videoprojecteur() const
		{
			return videoprojecteur_;
		}
