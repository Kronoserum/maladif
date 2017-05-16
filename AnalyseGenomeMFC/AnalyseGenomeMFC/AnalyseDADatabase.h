#pragma once

#include <iostream>
#include <string>
#include "Analyse.h"
#include "sqlite3.h"

using namespace std;

class AnalyseDADatabase
{
private:
	sqlite3 *database;

public:
	AnalyseDADatabase();
	~AnalyseDADatabase();

	void set_database(sqlite3 *database_in);

	int write_analyse(Analyse analyse);
	int read_analyse(Analyse &analyse, int id_in);

};
