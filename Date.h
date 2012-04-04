#ifndef _DATE_H_
#define _DATE_H_
class Date
{
	private :
		int jour_,mois_,annee_;
	
	public :
	
		/*
		* Constructeur
		*/
		Date(const int & jour,const int & mois,const int & annee);
		
		/*
		* Modifie la date
		*/
		void set_date(const int & jour,const int & mois,const int & annee);
		
		/*
		* Setters
		*/
		int get_jour() const;
		int get_mois() const;
		int get_annee() const;
		
		/*
		* Opérateur de comparaison
		*/
		bool operator==(const Date & b) const;
		bool operator<(const Date &b) const;
};
#endif
