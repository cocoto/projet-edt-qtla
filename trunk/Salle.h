#ifndef _SALLE_H_
#define _SALLE_H_
//Classe abstraite
enum Type_salle{Salle_TP,Salle_TD,Salle_Amphi};
class Salle{
	protected: //Permet d'utiliser l'attribut dans les classes héritées
		int numero_,capacite_;
		
	public:
        //Constructeur
		Salle(const int &numero, const int &capacite);

        //Getters
		int get_capacite() const;
		int get_numero() const;

        //Pré-condition : capacité est povitive ou nulle
        void set_capacite(const int &capacite) const;

        //Vérifie qu'une salle est compatible avec un nombre d'élève
        virtual bool verifier_capacite(const int & nb_eleve) const;

        //Comparaison des salles par leurs numéros
        bool operator<(const Salle &b) const;
        bool operator==(const Salle &s2);

        //Fonction virtuelle pure qui dépendra du type de la salle
        virtual bool verifier_type(const Type_salle & type) const =0;

		virtual ~Salle();
};
#endif
