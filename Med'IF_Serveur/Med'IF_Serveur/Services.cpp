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

int Services::ajouterMaladie(string nom, string mots)
{
	ServeurDA da;
	int i = da.ajouterMaladie(nom, mots);
	return i;
}

bool Services::modifierMaladie(string nom, string mots)
{
	ServeurDA da;
	bool b = da.mettreAJourMaladie(nom, mots);
	return b;
}

int Services::supprimerMaladie(string nom)
{
	ServeurDA da;
	int i = da.supprimerMaladie(nom);
	return i;
}

string Services::recupererMaladie(string nom)
{
	string mots;
	ServeurDA da;
	mots = da.getMotsMaladie(nom);
	return mots;
}

string Services::recupererNomsToutesMaladies()
{
	string listeNoms;
	ServeurDA da;
	listeNoms = da.getNomsMaladies();
	return listeNoms;
}

bool Services::modifierMetaDonnees(string meta) 
{
	ServeurDA da;
	return da.modifierMeta(meta);
}

