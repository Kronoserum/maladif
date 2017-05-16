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

