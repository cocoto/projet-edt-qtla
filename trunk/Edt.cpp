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



void Edt::creer_module(const std::string & Code, const std::string & Titre, const int & NombreCTD, const int & NombreTP,const int &noens)
{
    liste_module.insert(new Module(Code,Titre,NombreCTD,NombreTP,chercher_enseignant(noens)));
}



void Edt::ajouter_salle_amphi(const int & numero, const int & capacite)
{
    liste_salle.insert(new Salle_amphi(numero,capacite));
}


void Edt::creer_module(const std::string & Code, const std::string & Titre, const int & NombreCM, const int & NombreTD, const int & NombreTP,const int &noens)
{
    liste_module.insert(new Module(Code,Titre,NombreCM,NombreTD,NombreTP,chercher_enseignant(noens)));
}



void Edt::ajouter_salle_td(const int & numero, const int & capacite, const bool & videoprojecteur)
{
    liste_salle.insert(new Salle_td(numero,capacite,videoprojecteur));
}

void Edt::creer_etudiant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no){
    liste_etudiant.insert(new Etudiant(n,p,ap,am,no));
}

void Edt::creer_enseignant(const std::string &n ,const std::string &p,const std::string &ap ,const std::string &am,const int &no){
    liste_enseignant.insert(new Enseignant(n,p,ap,am,no));
}

void Edt::creer_groupe(const int &no,const Type_groupe &type){
    liste_groupe.insert(new Groupe(no,type));
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

const liste_etu& Edt::liste_etudiants(const int &no_groupe) const
{
    return chercher_groupe(no_groupe)->get_etudiants();
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
    else
    {
        throw "Module inexistant";
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
    else
    {
        throw "Salle inexistante";
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
    else
    {
        throw "Groupe inexistant";
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
    else{
        throw "Etudiant inexistant";
    }
}

Enseignant* Edt::chercher_enseignant(const int &noens) const{
    liste_ens::iterator it=liste_enseignant.begin();
    while(it!=liste_enseignant.end()&&(*it)->get_no_enseignant()!=noens)
    {
        it++;
    }
    if(it!=liste_enseignant.end())
    {
        return *it;
    }
    else
    {
        throw "Enseignant inexistant";
    }
}

Date* Edt::chercher_date(const Date &date) const{
    liste_dat::iterator it=liste_date.begin();
    while(it!=liste_date.end()&&!((**it)==date))
    {
        it++;
    }
    if(it!=liste_date.end())
    {
        return *it;
    }
    else
    {
        throw "Date inexistante";
    }
}

void Edt::inscrire_etudiant(const int &noetu,const int &nogrp){
    Etudiant* etu=chercher_etudiant(noetu);
    Groupe* grp=chercher_groupe(nogrp);
    if(!grp->contient_etudiant(etu))
    {
        grp->ajouter_etudiant(etu);
    }
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

void Edt::creer_creneau(const int &nsalle,const std::string &nmodule,Date* date,const int & ngroupe, const float &duree,const int &heure){
    liste_cren::iterator creneau=liste_creneau.begin();
    bool compatible=true;
    Salle* salle=chercher_salle(nsalle);
    Module* module=chercher_module(nmodule);
    Groupe* groupe=chercher_groupe(ngroupe);
    if(salle->verifier_capacite(groupe->nb_etu()))
    {
        while(creneau!=liste_creneau.end() && compatible)
        {
            if(
                    *(*creneau)->getSalle()==*salle &&
                    *(*creneau)->getDate()==*date &&
                    (
                        ((*creneau)->getHeure() <= heure && (*creneau)->getHeure()+(*creneau)->getDuree()>=heure )
                         ||((*creneau)->getHeure()>=heure && (*creneau)->getHeure() <= heure+duree )
                     )

               ) {compatible=false;}
            creneau++;
        }
        if(compatible)
        {
            liste_creneau.insert(new Creneau(salle,module,date,groupe,duree,heure));
        }
     }
    else{
        throw "Salle trop petite";
    }
}

void Edt::supprimer_salle(const int &nosalle){
    liste_cren::iterator it=liste_creneau.begin();
    while(it!=liste_creneau.end())
    {
        if((*it)->getSalle()->get_numero()==nosalle)
        {
           liste_creneau.erase(it);
        }
        it++;
    }
    liste_salle.erase(chercher_salle(nosalle));
}

void Edt::supprimer_module(const std::string & Code){
    liste_cren::iterator it=liste_creneau.begin();
    while(it!=liste_creneau.end())
    {
        if((*it)->getModule()->get_Code()==Code)
        {
           liste_creneau.erase(it);
        }
        it++;
    }
    liste_module.erase(chercher_module(Code));
}



void Edt::supprimer_enseignant(const int &noenseignant){
    liste_mod::iterator it=liste_module.begin();
    while(it!=liste_module.end())
    {
        if((*it)->get_responsable()->get_no_enseignant())
        {
            supprimer_module((*it)->get_Code());
        }
        it++;
    }
    liste_enseignant.erase(chercher_enseignant(noenseignant));
}

void Edt::supprimer_etudiant(const int &no){
    liste_grp::iterator it=liste_groupe.begin();
    while(it!=liste_groupe.end())
    {
        desinscrire_etudiant((*it)->get_numero(),no);
    }
    liste_etudiant.erase(chercher_etudiant(no));
}

void Edt::supprimer_groupe(const int no_groupe){
    liste_cren::iterator it=liste_creneau.begin();
    while(it!=liste_creneau.end())
    {
        if((*it)->getGroupe()->get_numero()==no_groupe)
        {
           liste_creneau.erase(it);
        }
        it++;
    }
    liste_groupe.erase(chercher_groupe(no_groupe));
}

void Edt::supprimer_date(const Date &date){
    liste_cren::iterator it=liste_creneau.begin();
    while(it!=liste_creneau.end())
    {
        if(*((*it)->getDate())==date)
        {
            liste_creneau.erase(it);
        }
        it++;
    }
    liste_date.erase(chercher_date(date));
}

void Edt::supprimer_creneau(Creneau *cren){
    liste_creneau.erase(cren);
}
