#include "Groupe.h"

Groupe::Groupe(const int &no,const Type_groupe &type):no_(no),type_(type),liste_etudiants_(),liste_modules_()
{}

void Groupe::ajouter_etudiant(Etudiant* etu){
    liste_etudiants_.insert(etu);
}

bool Groupe::supprimer_etudiant(const int &no_etudiant){
    liste_etu::iterator i=liste_etudiants_.begin();
    while((*i)->get_no_eleve() !=no_etudiant && i!=liste_etudiants_.end())
    {
        i++;
    }
    if(i==liste_etudiants_.end()){
        return false;
    }
    else{
        liste_etudiants_.erase(i);
        return true;
    }
}

int Groupe::nb_etu(){
    return liste_etudiants_.size();
}

bool Groupe::participe_a(Module* mod){
    return (liste_modules_.find(mod)!=liste_modules_.end());
}

Type_groupe Groupe::get_type() const{
    return type_;
}
liste_mod Groupe::get_modules() const{
    return liste_modules_;
}
liste_etu Groupe::get_etudiants() const{
    return liste_etudiants_;
}
 int Groupe::get_numero() const{
     return no_;
 }

void Groupe::ajouter_module(Module *mod){
    liste_modules_.insert(mod);
}

bool Groupe::supprimer_module(const std::string &cmodule){
    liste_mod::iterator it=liste_modules_.begin();

    while(it!=liste_modules_.end() && (*it)->get_Code()!=cmodule)
    {
        it++;
    }
    if(it==liste_modules_.end()){
        return false;
    }
    else{
        liste_modules_.erase(it);
        return true;
    }
}
