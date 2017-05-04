#include "stdafx.h"
#include "Patient.h"


Patient::Patient()
{
}

Patient::~Patient()
{
}

void Patient::set_id(long id_in)
{
	id = id_in;
}

void Patient::set_nom(string nom_in)
{
	nom = nom_in;
}

void Patient::set_prenom(string prenom_in)
{
	prenom = prenom_in;
}

void Patient::set_mail(string mail_in)
{
	mail = mail_in;
}

void Patient::set_mdp(string mdp_in)
{
	mdp = mdp_in;
}

long Patient::get_id()
{
	return id;
}

string Patient::get_nom()
{
	return nom;
}

string Patient::get_prenom()
{
	return prenom;
}

string Patient::get_mail()
{
	return mail;
}

string Patient::get_mdp()
{
	return mdp;
}
