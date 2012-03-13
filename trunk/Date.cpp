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
		

		bool Date::operator==(const Date & a,const Date & b) const
		{
			return a.jour_==b.jour_ && a.mois_==b.mois_ && a.annee_==b.annee_ ;
		}
		bool Date::operator<(const Date &a,const Date &b) const{
			if(a.annee_!=b.annee_){
				return a.annee_<b.annee_;
			}
			else if(a.mois_!=b.mois_){
				return a.mois_< b.mois;
			}
			else return a.jour<b.jour;

		}

