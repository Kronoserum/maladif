
#include "stdafx.h"
#include "ServicesMetier.h"
#include "ServeurDA.h"

ServicesMetier::ServicesMetier()
{

}


ServicesMetier::~ServicesMetier()
{

}

bool ServicesMetier::seConnecter(int id)
{
	// Recuperation de l'identifiant depuis un fichier txt
	ServeurDA da;
	int idLocal = da.getId();
	// Comparaison avec l'id puis return true/false
	if (idLocal != -1)
	{
		return false;
	}
	else if(id = idLocal)
	{
		return true;
	}
	return false;
}

bool ServicesMetier::seDeconnecter()
{
	return false;
}

bool ServicesMetier::ajouterMaladie(string nom, string mots)
{
	return false;
}

bool ServicesMetier::modifierMaladie(string nom)
{
	return false;
}

bool ServicesMetier::supprimerMaladie(string nom)
{
	return false;
}

string ServicesMetier::recupererMaladie(string nom)
{
	return string();
}
