#include "personne.h"

Personne::Personne(std::string n ,std::string p)
{
    nom_ = n;
    prenom_ = p;
}

Personne::Personne(std::string n ,std::string p , std::string ap ,std::string am)
{
    nom_ = n;
    prenom_ = p;
    adresse_p_= ap;
    adresse_m_ = am;
}

std::string Personne::get_nom()
{
    return nom_;
}

std::string Personne::get_prenom()
{
    return prenom_;
}

std::string Personne::get_adresse_p()
{
    return adresse_p_;
}

std::string Personne::get_adresse_m()
{
    return adresse_m_;
}

void Personne::set_nom(std::string n)
{
    nom_ = n;
}

void Personne::set_prenom(std::string p)
{
    prenom_ = p;
}

void Personne::set_adresse_p(std::string ap)
{
    adresse_p_= ap;
}

void Personne::set_adresse_m(std::string am)
{
    adresse_m_= am;
}
