#include "stdafx.h"
#include "MaladieDADatabase.h"

MaladieDADatabase::MaladieDADatabase()
{
}

MaladieDADatabase::~MaladieDADatabase()
{
}

void MaladieDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int MaladieDADatabase::write_maladie(Maladie maladie)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Serveur VALUES('" 
		+ to_string(maladie.get_id()) + "', '"
		+ maladie.get_nom() + " ','"
		+ maladie.get_typeMaladie() + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_maladie): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int MaladieDADatabase::read_maladie(Maladie &maladie, long id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Maladie WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_maladie): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		maladie.set_id(stol(results[0 + columns]));
		maladie.set_nom(results[1 + columns]);
		maladie.set_typeMaladie(results[2 + columns]);
	}
	
	sqlite3_free_table(results);

	return code;
}

