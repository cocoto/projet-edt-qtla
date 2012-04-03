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
    void ajouter_etudiant(Etudiant *etu);
    bool supprimer_etudiant(const int &no_etudiant);
    int nb_etu();
    bool participe_a(Module* mod);
    bool contient_etudiant(Etudiant* e);
    void ajouter_module(Module *mod);
    bool supprimer_module(const std::string &cmodule);
    int get_numero() const;
    Type_groupe get_type() const;
    liste_mod get_modules() const;
    const liste_etu &get_etudiants() const;
    bool operator<(const Groupe &b) const;
};

#endif // GROUPE_H
