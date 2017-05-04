#include "stdafx.h"
#include "Serveur.h"
#include "ServeurDA.h"

#include <fstream>
#include <iostream>
using namespace std;

ServeurDA::ServeurDA()
{
}

ServeurDA::~ServeurDA()
{
}

int ServeurDA::getId()
{
	int idLocal = -1;
	ifstream is("connexion.txt", ios::in);
	if (is)
	{
		string s;
		getline(is, s);
		idLocal = stoul(s, nullptr, 0);
		cout << "Identifiant stocke : " << idLocal << endl;
		is.close();
	}
	else {
		cout << "Erreur lors de l'ouverture du fichier" << endl;
	}
	return idLocal;
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
