#include "stdafx.h"
#include "Services.h"
#include "ServeurDA.h"


Services::Services()
{
}


Services::~Services()
{
}

bool Services::seConnecter(int id)
{
	// Recuperation de l'identifiant depuis un fichier txt
	ServeurDA da;
	int idLocal = da.getId();
	// Comparaison avec l'id puis return true/false
	if (idLocal == -1)
	{
		return false;
	}
	else if (id == idLocal)
	{
		return true;
	}
	return false;
}

bool Services::seDeconnecter()
{
	return false;
}

string Services::recupererMetaDonnees()
{
	return NULL;
}

bool Services::ajouterMaladie(string nom, string mots)
{
	return false;
}

bool Services::modifierMaladie(string nom)
{
	return false;
}

bool Services::supprimerMaladie(string nom)
{
	return false;
}

string Services::recupererMaladie(string nom)
{
	return NULL;
}

list<string> Services::recupererNomsToutesMaladies()
{
	return list<string>();
}

