#include "stdafx.h"
#include "PatientDADatabase.h"
#include "Patient.h"
#include "Database.h"

PatientDADatabase::PatientDADatabase()
{
	Database db;
	db.open_database();
	database = db.get_database();
}

PatientDADatabase::~PatientDADatabase()
{
}

void PatientDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int PatientDADatabase::write_patient(Patient patient)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Patient (nom, prenom, mail, mdp) VALUES('" +
			patient.get_nom() + "', '"
		+ patient.get_prenom() + "', '"
		+ patient.get_mail() + "', '"
		+ patient.get_mdp() + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_patient): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int PatientDADatabase::read_patient(Patient &patient, int id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Patient WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_patient): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		if (rows == 0)
		{
			return -1;
		}
		patient.set_id(stoi(results[0 + columns]));
		patient.set_nom(results[1 + columns]);
		patient.set_prenom(results[2 + columns]);
		patient.set_mail(results[3 + columns]);
		patient.set_mdp(results[4 + columns]);
	}
	
	sqlite3_free_table(results);

	return code;
}

