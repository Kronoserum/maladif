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

	int ajouterMaladie(string nom, string mots);

	bool modifierMaladie(string nom, string mots);

	int supprimerMaladie(string nom);

	string recupererMaladie(string nom);

	string recupererNomsToutesMaladies();
	bool modifierMetaDonnees(string meta);
};

