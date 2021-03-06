#include "stdafx.h"
#include "Patient.h"

Patient::Patient()
{
}

Patient::~Patient()
{
}

Patient::Patient(string nom_in, string pre_in, string mail_in, string mdp_in)
{
	nom = nom_in;
	prenom = pre_in;
	mail = mail_in;
	mdp = mdp_in;
}

void Patient::set_id(int id_in) {id = id_in; }

void Patient::set_nom(string nom_in) {nom = nom_in; }

void Patient::set_prenom(string prenom_in) {prenom = prenom_in; }

void Patient::set_mail(string mail_in) {mail = mail_in; }

void Patient::set_mdp(string mdp_in) {mdp = mdp_in; }

int Patient::get_id() {return id; }

string Patient::get_nom() {return nom; }

string Patient::get_prenom() {return prenom; }

string Patient::get_mail() {return mail; }

string Patient::get_mdp() {return mdp; }

string Patient::toString() {
	string res = "Patient : ";
	res.append(nom);
	res.append(" ");
	res.append(prenom);
	res.append(" : ");
	res.append(mail);
	return res;
}