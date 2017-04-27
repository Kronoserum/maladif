#pragma once

#include <string>
#include <list>
using namespace std;

class ServeurDA
{
public:
	ServeurDA();
	~ServeurDA();

	string getMetadonnees();
	list<string> getNomsMaladies();
	string getMotsMaladie(string nomMaladie);
};

