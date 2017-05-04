#pragma once

#include <iostream>
#include <string>
#include "Entreprise.h"
#include "sqlite3.h"

using namespace std;

class EntrepriseDADatabase
{
private:
	sqlite3 *database;

public:
	EntrepriseDADatabase();
	~EntrepriseDADatabase();

	void set_database(sqlite3 *database_in);

	int write_entreprise(Entreprise entreprise);
	int read_entreprise(Entreprise &ntreprise, long id_in);
};
