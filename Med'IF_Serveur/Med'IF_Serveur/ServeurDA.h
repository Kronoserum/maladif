#pragma once

#include <string>
#include <list>
using namespace std;

class ServeurDA
{
public:
	ServeurDA();
	~ServeurDA();

	int getId();
	string getMetadonnees();
	list<string> getNomsMaladies();
	string getMotsMaladie(string nomMaladie);
	bool ajouterMaladie(string nom, string mots);
};