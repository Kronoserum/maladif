#include <string>
#include <list>
#include <stdio.h>

#include "stdafx.h"
#include "Analyse.h"

using namespace std;


Analyse::Analyse()
{
}


Analyse::~Analyse()
{
}

Analyse::Analyse(int res_in, string date_in, int idMed, int idPat, int idMal, int idSer)
{
	resultat = res_in;
	dateAnalyse = date_in;
	idMedecin = idMed;
	idPatient = idPat;
	idMaladie = idMal;
	idServeur = idSer;
}

int Analyse::get_id(){return id; }

int Analyse::get_resultat(){return resultat; }

string Analyse::get_Date() {return dateAnalyse; }

int Analyse::get_IdMedecin() {return idMedecin; }

int Analyse::get_IdPatient() {return idPatient; }

int Analyse::get_IdMaladie() {return idMaladie; }

int Analyse::get_idServeur() { return idServeur; }

void Analyse::set_id(int id_in) {id = id_in; }
void Analyse::set_resultat(int res_in) {resultat = res_in; }

void Analyse::set_date(string date_in) { dateAnalyse = date_in; }
void Analyse::set_idMedecin(int id_in) { idMedecin = id_in; }
void Analyse::set_idPatient(int id_in) { idPatient = id_in; }
void Analyse::set_idMaladie(int id_in) { idMaladie = id_in; }
void Analyse::set_idServeur(int id_in) { idServeur = id_in; }

string Analyse::toString()
{
	string res = "IDAnalyse: ";
	res.append(to_string(id));
	res.append(";IDMedecin: ");
	res.append(to_string(idMedecin));
	res.append("; IDPatient: ");
	res.append(to_string(idPatient));
	res.append("; IDMaladie: ");
	res.append(to_string(idMaladie));
	res.append("; IDServeur: ");
	res.append(to_string(idServeur));
	res.append("; R�sultat: ");
	res.append(to_string(resultat));
	return res;
}
