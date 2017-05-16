#include "stdafx.h"
#include "ServeurDADatabase.h"

ServeurDADatabase::ServeurDADatabase()
{
}

ServeurDADatabase::~ServeurDADatabase()
{
}

void ServeurDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int ServeurDADatabase::write_serveur(Serveur serveur)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Serveur VALUES('" 
		+ to_string(serveur.get_id()) + "', '"
		+ serveur.get_description() + " ','"
		+ serveur.get_IPServeur() + "', '"
		+ to_string(serveur.get_idEntreprise()) + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_serveur): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int ServeurDADatabase::read_serveur(Serveur &serveur, long id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Serveur WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_serveur): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		serveur.set_id(stol(results[0 + columns]));
		serveur.set_description(results[1 + columns]);
		serveur.set_IPServeur(results[2 + columns]);
		serveur.set_idEntreprise(stol(results[3 + columns]));
	}
	
	sqlite3_free_table(results);

	return code;
}

