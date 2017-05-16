#pragma once

#include <iostream>
#include <string>
#include "Medecin.h"
#include "sqlite3.h"

using namespace std;

class MedecinDADatabase
{
private:
	sqlite3 *database;

public:
	MedecinDADatabase();
	~MedecinDADatabase();

	void set_database(sqlite3 *database_in);

	int write_medecin(Medecin medecin);
	int read_medecin(Medecin &medecin, int id_in);

};
