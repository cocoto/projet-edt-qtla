#ifndef _SALLE_H_
#define _SALLE_H_
class Salle{
	protected: //Permet d'utiliser l'attribut dans les classes héritées
		int numero_,capacite_;
		
	public:
		Salle(const int &numero, const int &capacite);
		int get_capacite() const;
		int get_numero() const;
		bool verifier_capacite(const int & nb_eleve) const;
		virtual bool verifier_type(const int & type) const =0;
		virtual ~Salle();
};
#endif
