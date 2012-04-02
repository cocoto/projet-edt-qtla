/*
 * Edt.cpp
 *
 *  Created on: 21 mars 2012
 *      Author: cocoto
 */
#include "Edt.h"
//Constructeur d'un nouvel emplois du temps vide
Edt::Edt():liste_creneau(),liste_date(),liste_enseignant(),liste_etudiant(),liste_groupe(),liste_module()
{
}

//Destruction de l'emplois du temps et de touts les objets liés
Edt::~Edt()
{
    liste_etu::iterator a;
    for(a=liste_etudiant.begin();a!=liste_etudiant.end();a++)
    {
        delete *a;
    }
    liste_mod::iterator b;
    for(b=liste_module.begin();b!=liste_module.end();b++)
    {
        delete *b;
    }
    liste_cren::iterator c;
    for(c=liste_creneau.begin();c!=liste_creneau.end();c++)
    {
        delete *c;
    }
    liste_dat::iterator d;
    for(d=liste_date.begin();d!=liste_date.end();d++)
    {
        delete *d;
    }
    liste_grp::iterator e;
    for(e=liste_groupe.begin();e!=liste_groupe.end();e++)
    {
        delete *e;
    }
    liste_ens::iterator f;
    for(f=liste_enseignant.begin();f!=liste_enseignant.end();f++)
    {
        delete *f;
    }
    liste_sal::iterator g;
    for(g=liste_salle.begin();g!=liste_salle.end();g++)
    {
        delete *g;
    }
}



void Edt::creer_module(const std::string & Code, const std::string & Titre, const int & NombreCTD, const int & NombreTP)
{
    liste_module.insert(new Module(Code,Titre,NombreCTD,NombreTP));
}



void Edt::ajouter_salle_amphi(const int & numero, const int & capacite)
{
    liste_salle.insert(new Salle_amphi(numero,capacite));
}


void Edt::creer_module(const std::string & Code, const std::string & Titre, const int & NombreCM, const int & NombreTD, const int & NombreTP)
{
    liste_module.insert(new Module(Code,Titre,NombreCM,NombreTD,NombreTP));
}



void Edt::ajouter_salle_td(const int & numero, const int & capacite, const bool & videoprojecteur)
{
    liste_salle.insert(new Salle_td(numero,capacite,videoprojecteur));
}



void Edt::ajouter_salle_amphi(const int & numero, const int & capacite, const bool & visio)
{
    liste_salle.insert(new Salle_amphi(numero,capacite,visio));
}

void Edt::ajouter_salle_td(const int & numero, const int & capacite)
{
    liste_salle.insert(new Salle_td(numero,capacite));
}

void Edt::ajouter_salle_tp(const int & numero, const int & capacite, const int & nbmachine)
{
    liste_salle.insert(new Salle_tp(numero,capacite,nbmachine));
}



void Edt::ajouter_date(const int & jour, const int & mois, const int & annee)
{
    liste_date.insert(new Date(jour,mois,annee));
}

const liste_etu& Edt::liste_etudiants() const
{
    return liste_etudiant;
}

liste_etu Edt::liste_etudiants(const int &no_groupe) const
{
    Groupe* grp=chercher_groupe(no_groupe);
    liste_etu resultat;
    liste_etu::iterator it;
    for(it=liste_etudiant.begin();it!=liste_etudiant.end();it++)
    {
        if(grp->get_etudiants().find(*it)!=grp->get_etudiants().end())
        {
            resultat.insert(*it);
        }
    }
    return resultat;
}

const liste_cren& Edt::liste_creneaux() const
{
    return liste_creneau;
}

const liste_mod& Edt::liste_modules() const
{
    return liste_module;
}

const liste_ens& Edt::liste_enseignants() const
{
    return liste_enseignant;
}

const liste_grp& Edt::liste_groupes() const
{
    return liste_groupe;
}

const liste_dat& Edt::liste_dates() const
{
    return liste_date;
}

Module* Edt::chercher_module(const std::string & code) const
{
    liste_mod::iterator it=liste_module.begin();
    while(it!=liste_module.end() && (*it)->get_Code()!=code)
    {
        it++;
    }
    if(it!=liste_module.end())
    {
        return (*it);
    }
}

Salle*  Edt::chercher_salle(const int &salle) const
{
    liste_sal::iterator it=liste_salle.begin();
    while(it!=liste_salle.end()&& (*it)->get_numero()!=salle)
    {
        it++;
    }
    if(it!=liste_salle.end())
    {
        return (*it);
    }
}
Groupe* Edt::chercher_groupe(const int & no_groupe) const
{
    liste_grp::iterator it=liste_groupe.begin();
    while(it!=liste_groupe.end()&&(*it)->get_numero()!=no_groupe){
        it++;
    }
    if(it!=liste_groupe.end())
    {
        return *it;
    }
}

Etudiant* Edt::chercher_etudiant(const int &noetu) const{
    liste_etu::iterator it=liste_etudiant.begin();
    while(it!=liste_etudiant.end()&&(*it)->get_no_eleve()!=noetu)
    {
        it++;
    }
    if(it!=liste_etudiant.end())
    {
        return *it;
    }
}
void Edt::inscrire_etudiant(const int &noetu,const int &nogrp){
    chercher_groupe(nogrp)->ajouter_etudiant(chercher_etudiant(noetu));
}

void Edt::desinscrire_etudiant(const int &no_groupe,const int &no_etudiant){
    chercher_groupe(no_groupe)->supprimer_etudiant(no_etudiant);
}
void Edt::inscrire_module(const int &no_groupe,std::string code){
    chercher_groupe(no_groupe)->ajouter_module(chercher_module(code));
}
void Edt::desinscrire_module(const int &no_groupe,std::string code){
    chercher_groupe(no_groupe)->supprimer_module(code);
}

int creer_creneau(const Salle &salle,const Module &module,const Date & date,const Groupe & groupe, const float &duree,const int &heure){

}
