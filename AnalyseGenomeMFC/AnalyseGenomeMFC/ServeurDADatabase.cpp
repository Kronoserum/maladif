#include "stdafx.h"
#include "ServeurDADatabase.h"
#include <vector>
#include "Database.h"

ServeurDADatabase::ServeurDADatabase()
{
	Database db;
	db.open_database();
	database = db.get_database();
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

	string sqlInsertStr = "INSERT INTO Serveur (description,ipServeur, idEntreprsie) VALUES('" 
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

int ServeurDADatabase::read_serveur(Serveur &serveur, int id_in)
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
		serveur.set_id(stoi(results[0 + columns]));
		serveur.set_description(results[1 + columns]);
		serveur.set_IPServeur(results[2 + columns]);
		serveur.set_idEntreprise(stol(results[3 + columns]));
	}
	
	sqlite3_free_table(results);

	return code;
}

vector<Serveur> ServeurDADatabase::read_all_servers()
{
	vector<Serveur>retour;

	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Serveur;";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (readServers): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			Serveur serveur;

			serveur.set_id(stoi(results[i*columns+0]));
			serveur.set_description(results[i*columns + 1]);
			serveur.set_IPServeur(results[i*columns + 2]);
			serveur.set_idEntreprise(stol(results[i*columns + 3]));

			retour.push_back(serveur);
		}



	}

	sqlite3_free_table(results);

	return retour;
}
