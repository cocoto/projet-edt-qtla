#include "Personne.h"

Personne::Personne(const std::string &n ,const std::string &p)
{
    nom_ = n;
    prenom_ = p;
}

Personne::Personne(const std::string &n ,const std::string &p ,const std::string &ap ,const std::string &am)
{
    nom_ = n;
    prenom_ = p;
    adresse_p_= ap;
    adresse_m_ = am;
}

std::string Personne::get_nom() const
{
    return nom_;
}

std::string Personne::get_prenom() const
{
    return prenom_;
}

std::string Personne::get_adresse_p() const
{
    return adresse_p_;
}

std::string Personne::get_adresse_m() const
{
    return adresse_m_;
}

void Personne::set_nom(const std::string &n)
{
    nom_ = n;
}

void Personne::set_prenom(const std::string &p)
{
    prenom_ = p;
}

void Personne::set_adresse_p(const std::string &ap)
{
    adresse_p_= ap;
}

void Personne::set_adresse_m(const std::string &am)
{
    adresse_m_= am;
}
