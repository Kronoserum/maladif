#pragma once

#include <string>
using namespace std;

class ServicesMetier
{
	
public:
	ServicesMetier();
	~ServicesMetier();

	bool seConnecter(int id);

	bool seDeconnecter();

	bool ajouterMaladie(string nom, string mots);

	bool modifierMaladie(string nom);

	bool supprimerMaladie(string nom);

	string recupererMaladie(string nom);
};

