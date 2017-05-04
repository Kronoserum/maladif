#include "stdafx.h"
#include "MedecinDADatabase.h"

MedecinDADatabase::MedecinDADatabase()
{
}

MedecinDADatabase::~MedecinDADatabase()
{
}

void MedecinDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int MedecinDADatabase::write_medecin(Medecin medecin)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Medecin VALUES('" 
		+ to_string(medecin.get_id()) + "', '"
		+ medecin.get_nom() + "', '"
		+ medecin.get_prenom() + "', '"
		+ medecin.get_adresse() + "', '"
		+ to_string(medecin.get_salaire()) + "', '"
		+ medecin.get_mdp() + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_medecin): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int MedecinDADatabase::read_medecin(Medecin &medecin, long id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM medecin WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_medecin): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		medecin.set_id(stol(results[0 + columns]));
		medecin.set_nom(results[1 + columns]);
		medecin.set_prenom(results[2 + columns]);
		medecin.set_adresse(results[3 + columns]);
		medecin.set_salaire(stod(results[4 + columns]));
		medecin.set_mdp(results[5 + columns]);
	}
	
	sqlite3_free_table(results);

	return code;
}
