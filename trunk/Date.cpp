#include "Date.h"

		Date::Date(const int & jour,const int & mois,const int & annee):jour_(jour),mois_(mois),annee_(annee)
		{
		}
		
		void  Date::set_date(const int & jour,const int & mois,const int & annee)
		{
			jour_=jour;
			mois_=mois;
			annee_=annee;
		}
		

		int Date::get_jour() const
		{
			return jour_;
		}
		int Date::get_mois() const
		{
			return mois_;
		}
		int Date::get_annee() const
		{
			return annee_;
		}
		

		bool Date::operator==(const Date & b) const
		{
			return jour_==b.jour_ && mois_==b.mois_ && annee_==b.annee_ ;
		}
		bool Date::operator<(const Date &b) const{
			if(annee_!=b.annee_){
				return annee_<b.annee_;
			}
			else if(mois_!=b.mois_){
                return mois_< b.mois_;
			}
            else return jour_<b.jour_;

		}

