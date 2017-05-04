#pragma once

#include <string>
#include <list>
using namespace std;

class Services
{
public:
	Services();
	~Services();

	bool seConnecter(int id);

	bool seDeconnecter();

	string recupererMetaDonnees();

	bool ajouterMaladie(string nom, string mots);

	bool modifierMaladie(string nom);

	bool supprimerMaladie(string nom);

	string recupererMaladie(string nom);

	list<string> recupererNomsToutesMaladies();
};

