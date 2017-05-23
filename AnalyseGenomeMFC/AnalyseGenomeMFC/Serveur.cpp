#include <string>
#include <list>
#include <stdio.h>

#include "stdafx.h"
#include "Serveur.h"

using namespace std;


Serveur::Serveur()
{
}


Serveur::~Serveur()
{
}

Serveur::Serveur(string ip_in, string desc_in, int ent_in)
{
	IPServeur = ip_in;
	description = desc_in;
	idEntreprise = ent_in;
}

void Serveur::set_id(int id_in) { id = id_in; }
void Serveur::set_IPServeur(string ip_in) { IPServeur = ip_in; }
void Serveur::set_description(string desc_in) { description = desc_in; }
void Serveur::set_idEntreprise(int entr_in) { idEntreprise = entr_in; }

int Serveur::get_id() { return id; }
string Serveur::get_IPServeur() { return IPServeur; }
string Serveur::get_description() { return description; }
int Serveur::get_idEntreprise() { return idEntreprise; }

string Serveur::toString()
{
	string res = "IDServeur :";
	res.append(to_string(id));
	res.append("; IPServeur :");
	res.append(IPServeur);
	res.append("; Description :");
	res.append(description);
	res.append("; IDEntreprise :");
	res.append(to_string(idEntreprise));
	return res;
}