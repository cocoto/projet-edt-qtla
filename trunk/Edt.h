/*
 * edt.h
 *
 *  Created on: 14 mars 2012
 *      Author: cocoto
 */
#include<iostream>
#include "Etudiant.h"
#include "Enseignant.h"
#include "Creneau.h"
#include "Date.h"
#include "Salle.h"
#include "Salle_td.h"
#include "Salle_tp.h"
#include "Salle_amphi.h"
#include "Module.h"
#include"Compare.h"
#include <set>
#ifndef EDT_H_
#define EDT_H_
typedef std::set<Etudiant*,compare<Etudiant> > liste_etu;
typedef std::set<Module*,compare<Module> > liste_mod;
typedef std::set<Date*,compare<Date> > liste_dat;
typedef std::set<Creneau*,compare<Creneau> > liste_cren;
typedef std::set<Enseignant*,compare<Enseignant> > liste_ens;
typedef std::set<Groupe*,compare<Groupe> > liste_grp;
typedef std::set<Salle*,compare<Salle> > liste_sal;
class Edt {
private:
    liste_etu liste_etudiant;
	liste_mod liste_module;
	liste_dat liste_date;
    liste_cren liste_creneau;
    liste_ens liste_enseignant;
    liste_grp liste_groupe;
    liste_sal liste_salle;
public:
	//Createurs d'objets
	void creer_etudiant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no);
    void creer_enseignant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no);
    void creer_groupe(const int &no,const Type_groupe &type);
    void creer_module(const std::string & Code,const std::string & Titre,const int & NombreCM,const int & NombreTD,const int & NombreTP,const int &noens);//Mode CM TD TP
    void creer_module(const std::string & Code,const std::string & Titre,const int & NombreCTD,const int & NombreTP,const int &noens); //Mode CTDi
	void ajouter_date(const int & jour,const int & mois,const int & annee);
	void ajouter_salle_amphi(const int &numero, const int &capacite);
	void ajouter_salle_amphi(const int &numero, const int &capacite,const bool & visio);
	void ajouter_salle_td(const int &numero, const int &capacite,const bool & videoprojecteur);
	void ajouter_salle_td(const int &numero, const int &capacite);
	void ajouter_salle_tp(const int &numero, const int &capacite,const int & nbmachine);

    void supprimer_salle(const int &nosalle);
    void supprimer_date(const Date &date);
    void supprimer_module(const std::string & Code);
    void supprimer_enseignant(const int &noenseignant);
    void supprimer_etudiant(const int &no);
    void supprimer_groupe(const int no_groupe);
    void supprimer_creneau(Creneau *cren);

    void creer_creneau(const int &nsalle,const std::string &nmodule,Date * date,const int & ngroupe, const float &duree,const int &heure);

    //Affectations
    void inscrire_etudiant(const int &noetu,const int &nogrp);
	void desinscrire_etudiant(const int &no_groupe,const int &no_etudiant);
	void inscrire_module(const int &no_groupe,std::string code);
	void desinscrire_module(const int &no_groupe,std::string code);
	int modifier_creneau(const Salle &salle,const Module &module,const Date & date,const Groupe & groupe, const float &duree,const int &heure);

	//Getters autorisés pour l'interface graphique
	//Ces fonctions permettent à l'interface graphique de n'utiliser les fonctions const des objets
	//Par exemple, obtenir les information sur les créneaux mais pas les modifier
    const liste_etu& liste_etudiants() const;//Renvois la liste des numéros de tous les étudiants
    const liste_etu &liste_etudiants(const int &no_groupe) const; //Renvois la liste des étudiants d'un groupe
	const liste_cren& liste_creneaux() const;
	const liste_mod& liste_modules() const;
    const liste_ens& liste_enseignants() const;
    const liste_grp& liste_groupes() const;
	const liste_dat& liste_dates() const;

	Edt();
	~Edt();

protected:
    Module* chercher_module(const std::string & code) const;
    Salle*  chercher_salle(const int &salle) const;
    Groupe* chercher_groupe(const int &nogroupe) const;
    Etudiant* chercher_etudiant(const int &noetu) const;
    Enseignant* chercher_enseignant(const int &noens) const;
    Date* chercher_date(const Date &date) const;


};

#endif /* EDT_H_ */
