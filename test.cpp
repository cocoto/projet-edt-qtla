#include <iostream>

#include "Edt.h"

int main(){
    //CREATION DE l'OBJET D'EMPLOIS DU TEMPS
    Edt edt;

    //CREATION DE DEUX ETUDIANTS
    edt.creer_etudiant("Tonneau","Quentin","9, rue des aubépines","qtonneau@gmail.com",2);
    edt.creer_etudiant("Dtc","J'ai dit","jesaispas","abla",1);

    //CREATION DE GROUPES VIERGES
     edt.creer_groupe(600,CM);
     edt.creer_groupe(601,TD);
     edt.creer_groupe(602,TP);

     //AFFECTATION DES ETUDIANTS AUX GROUPES
     edt.inscrire_etudiant(2,601);
     edt.inscrire_etudiant(2,601); //Il ne se passe rien ici, pas de doublons
     edt.inscrire_etudiant(1,601);
     edt.inscrire_etudiant(1,600);
     edt.inscrire_etudiant(1,602);

     //AFFICHAGE DE TOUS LES ETUDIANTS DU GROUPE 601
     //ON NOTE LE TRIE AUTOMATIQUE PAR NUMERO d'ETUDIANT
     liste_etu::iterator it=edt.liste_etudiants(601).begin();
     while(it!=edt.liste_etudiants(601).end())
     {
         std::cout<<"Eleve numero "<<(*it)->get_no_eleve()<<std::endl;
         it++;
     }

     //RETRAIT D'UN ELEVE
     edt.desinscrire_etudiant(601,1);

     //AFFICHAGE
     it=edt.liste_etudiants(601).begin();
     while(it!=edt.liste_etudiants(601).end())
     {
         std::cout<<"Eleve numero "<<(*it)->get_no_eleve()<<std::endl;
         it++;
     }

     //AJOUT D'UNE DATE DE COURS POSSIBLE
    try{
     edt.ajouter_date(1,12,2012);
    }
     catch(const char* e){
         std::cout<<e<<std::endl;
     }

    //AJOUT D'UNE SALLE AMPHI DE 123 places
    edt.ajouter_salle_amphi(1,123,true);

    //AJOUT D'UN ENSEIGNANT
    edt.creer_enseignant("toto","laburne","9, rue du poil","lol@lolilol",1);
    //AJOUT D'UN MODULE ET AFFECTATION AUX GROUPES de TP TD CM ASSOCIES
    edt.creer_module("As01","Manufacture",12,12,12,1);
    edt.inscrire_module(601,"As01");
    edt.inscrire_module(600,"As01");
    edt.inscrire_module(602,"As01");


    //CREATION D'UN CRENEAU
    edt.creer_creneau(1,"As01",new Date(1,12,2012),601,2.5,12);


    liste_cren::iterator itcren = edt.liste_creneaux().begin();
    while(itcren!=edt.liste_creneaux().end()){
        std::cout<<"Cours de "<<(*itcren)->getModule()->get_Code()<<" en salle "<<(*itcren)->getSalle()->get_numero()<< "pour le groupe "<<
                   (*itcren)->getGroupe()->get_numero()<<" de "<<(*itcren)->getHeure()<<"h à "<<(*itcren)->getHeure()+(*itcren)->getDuree()<<"h le ."<<
                (*itcren)->getDate()->get_jour()<<"/"<<(*itcren)->getDate()->get_mois()<<"/"<<(*itcren)->getDate()->get_annee()<<std::endl;
        itcren++;
    }

    //CREATION D'UN CRENEAU NON COMPATIBLE AUTOMATIQUEMENT AVORTE
    edt.creer_creneau(1,"As01",new Date(1,12,2012),602,2,11);

    itcren=edt.liste_creneaux().begin();
    while(itcren!=edt.liste_creneaux().end()){
        std::cout<<"Cours de "<<(*itcren)->getModule()->get_Code()<<" en salle "<<(*itcren)->getSalle()->get_numero()<< "pour le groupe "<<
                   (*itcren)->getGroupe()->get_numero()<<" de "<<(*itcren)->getHeure()<<"h à "<<(*itcren)->getHeure()+(*itcren)->getDuree()<<"h le ."<<
                (*itcren)->getDate()->get_jour()<<"/"<<(*itcren)->getDate()->get_mois()<<"/"<<(*itcren)->getDate()->get_annee()<<std::endl;
        itcren++;
    }

    //SUPRESSION D'UNE SALLE
    //edt.supprimer_salle(1);

    //SUPRESSION D'UN GROUPE
    //edt.supprimer_groupe(1);

    //SUPRESSION D'UN MODULE
    //edt.supprimer_module("As01");

    //SUPPRESSION D'UN ENSEIGNANT
    //edt.supprimer_enseignant(1);

    //SUPPRESSION D'UNE DATE
    //edt.supprimer_date(Date(1,12,2012));


    //SUPPRESSION DU PLUS VIEUX CRENEAU
    //edt.supprimer_creneau(*(edt.liste_creneaux().begin()));

    itcren=edt.liste_creneaux().begin();
    while(itcren!=edt.liste_creneaux().end()){
        std::cout<<"Cours de "<<(*itcren)->getModule()->get_Code()<<" en salle "<<(*itcren)->getSalle()->get_numero()<< "pour le groupe "<<
                   (*itcren)->getGroupe()->get_numero()<<" de "<<(*itcren)->getHeure()<<"h à "<<(*itcren)->getHeure()+(*itcren)->getDuree()<<"h le ."<<
                (*itcren)->getDate()->get_jour()<<"/"<<(*itcren)->getDate()->get_mois()<<"/"<<(*itcren)->getDate()->get_annee()<<std::endl;
        itcren++;
    }

    //SUPPRESSION D'UN ETUDIANT
    //edt.supprimer_etudiant(2);
    it=edt.liste_etudiants(601).begin();
    while(it!=edt.liste_etudiants(601).end())
    {
        std::cout<<"Eleve numero "<<(*it)->get_no_eleve()<<std::endl;
        it++;
    }

    //TEST D'EXCEPTION
    edt.ajouter_salle_amphi(2,0,true);
    try{
        edt.creer_creneau(2,"As01",new Date(1,12,2012),601,1.0,1);
    }
    catch(const char* e)
    {
        //Affichage d'une fenetre d'alerte dans le cadre d'une interface graphique
        std::cout<<"Exception : "<<e<<std::endl;
    }

    return  0;
}
