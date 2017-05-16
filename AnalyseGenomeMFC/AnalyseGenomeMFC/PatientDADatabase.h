#pragma once

#include <iostream>
#include <string>
#include "Patient.h"
#include "sqlite3.h"

using namespace std;

class PatientDADatabase
{
private:
	sqlite3 *database;

public:
	PatientDADatabase();
	~PatientDADatabase();

	void set_database(sqlite3 *database_in);

	int write_patient(Patient patient);
	int read_patient(Patient &patient, long id_in);
};
