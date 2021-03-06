#include "stdafx.h"
#include "Medecin.h"


Medecin::Medecin()
{
}

Medecin::~Medecin()
{
}

Medecin::Medecin(string nom_in, string prenom_in, string adr_in, string mdp_in, double sal_in)
{
	nom = nom_in;
	prenom = prenom_in;
	adresse = adr_in;
	mdp = mdp_in;
	salaire = sal_in;
}

void Medecin::set_id(int id_in) {id = id_in; }

void Medecin::set_nom(string nom_in) {nom = nom_in; }

void Medecin::set_prenom(string prenom_in) {prenom = prenom_in; }

void Medecin::set_adresse(string adr_in) {adresse = adr_in; }

void Medecin::set_mdp(string mdp_in) {mdp = mdp_in; }

void Medecin::set_salaire(double sal_in) {salaire = sal_in; }

int Medecin::get_id() {return id; }

string Medecin::get_nom() {return nom; }

string Medecin::get_prenom() {return prenom; }

string Medecin::get_adresse() {return adresse; }

string Medecin::get_mdp() {return mdp; }

double Medecin::get_salaire() {return salaire; }
