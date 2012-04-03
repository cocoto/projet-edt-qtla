#ifndef _SALLE_H_
#define _SALLE_H_
enum Type_salle{Salle_TP,Salle_TD,Salle_Amphi};
class Salle{
	protected: //Permet d'utiliser l'attribut dans les classes héritées
		int numero_,capacite_;
		
	public:
		Salle(const int &numero, const int &capacite);
		int get_capacite() const;
		int get_numero() const;
		bool verifier_capacite(const int & nb_eleve) const;
        bool operator<(const Salle &b) const;
        virtual bool verifier_type(const Type_salle & type) const =0;
		virtual ~Salle();
        bool operator==(const Salle &s2);
};
#endif
