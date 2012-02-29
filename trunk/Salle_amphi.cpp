#include "Salle_amphi.h"
		Salle_amphi::Salle_amphi(const int &numero, const int &capacite,const bool & visio):Salle(numero,capacite),visio_conference_(visio)
		{
		}
		Salle_amphi::Salle_amphi(const int &numero, const int &capacite):Salle(numero,capacite),visio_conference_(false)
		{	
		}
				
		void Salle_amphi::set_visio(const bool & visio)
		{
			visio_conference_=visio;
		}
		
		bool Salle_amphi::get_visio() const
		{
			return visio_conference_;
		}
