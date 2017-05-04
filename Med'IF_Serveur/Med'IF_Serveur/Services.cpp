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
	string meta;
	ServeurDA da;
	meta = da.getMetadonnees();
	return meta;
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
	string mots;
	ServeurDA da;
	mots = da.getMotsMaladie(nom);
	return mots;
}

list<string> Services::recupererNomsToutesMaladies()
{
	list<string> listeNoms;
	ServeurDA da;
	listeNoms = da.getNomsMaladies();
	return listeNoms;
}

