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

long Analyse::get_id(){return id; }

int Analyse::get_resultat(){return resultat; }

string Analyse::get_Date() {return dateAnalyse; }

long Analyse::get_IdMedecin() {return idMedecin; }

long Analyse::get_IdPatient() {return idPatient; }

long Analyse::get_IdMaladie() {return idMaladie; }

long Analyse::get_idServeur() { return idServeur; }

void Analyse::set_id(long id_in) {id = id_in; }
void Analyse::set_resultat(int res_in) {resultat = res_in; }

void Analyse::set_date(string date_in) { dateAnalyse = date_in; }
void Analyse::set_idMedecin(long id_in) { idMedecin = id_in; }
void Analyse::set_idPatient(long id_in) { idPatient = id_in; }
void Analyse::set_idMaladie(long id_in) { idMaladie = id_in; }
void Analyse::set_idServeur(long id_in) { idServeur = id_in; }

