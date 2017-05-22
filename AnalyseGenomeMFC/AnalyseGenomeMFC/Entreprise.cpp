#include <string>
#include <list>
#include <stdio.h>

#include "stdafx.h"
#include "Entreprise.h"

using namespace std;


Entreprise::Entreprise()
{
}


Entreprise::~Entreprise()
{
}

Entreprise::Entreprise(string desc, string nom_in)
{
	description = desc;
	nom = nom_in;
}

int Entreprise::get_id() {return id; }
string Entreprise::get_nom() { return nom;}

string Entreprise::get_description() {return description; }

void Entreprise::set_id(int id_in) {id = id_in; }

void Entreprise::set_nom(string nom_in) {nom = nom_in;}

void Entreprise::set_description(string desc_in) {description = desc_in;}