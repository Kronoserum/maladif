#pragma once

#include <string>

using namespace std;
class Serveur
{
public:
	Serveur();
	~Serveur();
private:
	unsigned int idServeur;
	string IPServeur, description;
};

