#pragma once

#include <string>

using namespace std;

class ServeurA
{
private :
	unsigned int idEntreprise;
	string metadonnees;

public:
	Serveur(unsigned int id, string metadonneesS);
	unsigned int getId();
	string getMetadonnees();
	~Serveur();
};

