#include "Date.h"

        Date::Date(const int & jour,const int & mois,const int & annee)
		{
            bool bisextile=(annee%400==0)||(annee%4==0 && annee%100!=0);
            int taille_mois[13]={0,31,bisextile?29:28,31,30,31,30,31,31,30,31,30,31};
            if(mois<=12 && mois>0)
            {
                if(jour>0 && jour<=taille_mois[mois])
                {
                    jour_=jour;
                    mois_=mois;
                    annee_=annee;
                }
                else{
                    throw "Date invalide";
                }
            }
            else{
                throw "Date invalide";
            }
        }
		
		void  Date::set_date(const int & jour,const int & mois,const int & annee)
		{
            bool bisextile=(annee%400==0)||(annee%4==0 && annee%100!=0);
            int taille_mois[13]={0,31,bisextile?29:28,31,30,31,30,31,31,30,31,30,31};
            if(mois<=12 && mois>0)
            {
                if(jour>0 && jour<=taille_mois[mois])
                {
                    jour_=jour;
                    mois_=mois;
                    annee_=annee;
                }
                else{
                    throw "Date invalide";
                }
            }
            else{
                throw "Date invalide";
            }
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

