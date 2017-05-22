#include "stdafx.h"
#include "EntrepriseDADatabase.h"

EntrepriseDADatabase::EntrepriseDADatabase()
{
}

EntrepriseDADatabase::~EntrepriseDADatabase()
{
}

void EntrepriseDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int EntrepriseDADatabase::write_entreprise(Entreprise entreprise)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Entreprise (nom,description) VALUES('" 
		+ entreprise.get_nom() + "', '"
		+ entreprise.get_description() + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_entreprise): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int EntrepriseDADatabase::read_entreprise(Entreprise &entreprise, int id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Entreprise WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_entreprise): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		entreprise.set_id(stol(results[0 + columns]));
		entreprise.set_nom(results[1 + columns]);
		entreprise.set_description(results[2 + columns]);
	}
	
	sqlite3_free_table(results);

	return code;
}
