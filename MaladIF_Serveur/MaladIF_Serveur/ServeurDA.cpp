#include <string>
#include <list>

#include "stdafx.h"
#include "Serveur.h"
#include "ServeurDA.h"

using namespace std;

ServeurDA::ServeurDA()
{
}

ServeurDA::~ServeurDA()
{
}

string ServeurDA::getMetadonnees()
{
	string meta;
	// Lire le fichier dictionnaire et extraire la premiere ligne
	return meta;
}

list<string> ServeurDA::getNomsMaladies()
{
	list<string> maladies;
	// Lire le fichier dictionnaire et extraire le noms des maladies
	return maladies;
}

string ServeurDA::getMotsMaladie(string nomMaladie)
{
	string mots;
	// Lire le dictionnaire et extraire les mots associés à une maladie
	return mots;
}
