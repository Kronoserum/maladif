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
	ifstream is("Connexion.txt", ios::in);
	if (is)
	{
		string s;
		getline(is, s);
		idLocal = stoul(s, nullptr, 0);
		is.close();
	}
	else {
		cerr << "Erreur lors de l'ouverture du fichier de connexion" << endl;
	}
	return idLocal;
}

string ServeurDA::getMetadonnees()
{
	string meta;
	// Lire le fichier dictionnaire et extraire la premiere ligne
	ifstream is("Dictionnaire.txt", ios::in);
	if (is)
	{
		getline(is, meta);
		is.close();
	}
	else {
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return meta;
}

list<string> ServeurDA::getNomsMaladies()
{
	list<string> maladies;
	// Lire le fichier dictionnaire et extraire le noms des maladies
	ifstream is("Dictionnaire.txt", ios::in);
	if (is)
	{
		string tmp;
		getline(is, tmp); // Metadonnees
		while (getline(is, tmp))
		{
			maladies.push_back(tmp.substr(0, tmp.find(":")));			
		}
		is.close();
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return maladies;
}

string ServeurDA::getMotsMaladie(string nomMaladie)
{
	string mots;
	// Lire le dictionnaire et extraire les mots associés à une maladie
	ifstream is("Dictionnaire.txt", ios::in);
	if (is)
	{
		string tmp;
		getline(is, tmp); // Metadonnees
		while (getline(is, tmp))
		{
			string name = tmp.substr(0, tmp.find(":"));
			if (name.compare(nomMaladie)==0)
			{
				// On a trouvé la bonne maladie
				mots = tmp.substr(tmp.find(":")+1, tmp.size() - tmp.find(":") -2);
				is.close();
				return mots;
			}
		}
		is.close();
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return mots;
}

bool ServeurDA::ajouterMaladie(string nom, string mots)
{
	return false;
}