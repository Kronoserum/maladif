#pragma once

#include <iostream>
#include <string>
#include "Serveur.h"
#include "sqlite3.h"

using namespace std;

class ServeurDADatabase
{
private:
	sqlite3 *database;

public:
	ServeurDADatabase();
	~ServeurDADatabase();

	void set_database(sqlite3 *database_in);

	int write_serveur(Serveur serveur);
	int read_serveur(Serveur &serveur, long id_in);

};
