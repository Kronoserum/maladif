#include <string>

#include "stdafx.h"
#include "ServicesMetier.h"

using namespace std;

ServicesMetier::ServicesMetier()
{

}


ServicesMetier::~ServicesMetier()
{

}

bool ServicesMetier::seConnecter(unsigned int id)
{
	// Recuperation de l'identifiant depuis un fichier txt
	// Comparaison avec l'id puis return true/false
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
