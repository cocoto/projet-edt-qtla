#ifndef GROUPE_H
#define GROUPE_H
#include "set"
#include "Etudiant.h"
#include "Module.h"
#include "Compare.h"
class Module;
enum Type_groupe {TD,TP,CM};
typedef std::set<Etudiant*,compare<Etudiant> > liste_etu;
typedef std::set<Module*,compare<Module> > liste_mod;
class Groupe{
private:
    liste_etu liste_etudiants_;
    liste_mod liste_modules_;
    int no_;
    Type_groupe type_;
public:
    Groupe(const int &no,const Type_groupe &type);

    //Ajoute un étudiant au groupe
    void ajouter_etudiant(Etudiant *etu);

    //Supprime l'etudiant s'il existe
    bool supprimer_etudiant(const int &no_etudiant);

    //Retourne la capacité du groupe
    int nb_etu();

    //Permet de vérifier si le groupe participe à un module
    bool participe_a(Module* mod);

    //Permet de vérifier qu'un étudiant est inscrit dans ce groupe
    bool contient_etudiant(Etudiant* e);

    //Ajout et retrait des modules inscrits par le groupe
    void ajouter_module(Module *mod);
    bool supprimer_module(const std::string &cmodule);

    //Getters
    int get_numero() const;
    Type_groupe get_type() const;
    const liste_mod &get_modules() const;
    const liste_etu &get_etudiants() const;
    bool operator<(const Groupe &b) const;
};

#endif // GROUPE_H
