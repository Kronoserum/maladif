#include "stdafx.h"
#include "Database.h"

// database implementation inspired by https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/

Database::Database()
{
}

Database::~Database()
{
}

sqlite3 * Database::get_database()
{
	return database;
}

int Database::open_database()
{
	int code;

	code = sqlite3_open(database_name, &database);
	
	if (code != 0)
	{
		cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(database) << endl;
		sqlite3_close(database);
	}

	return code;
}

int Database::close_database()
{
	sqlite3_close(database);

	return 0;
}

int Database::create_tables()
{
	int code;
	char *error;

	const char *sqlCreateTable = "CREATE TABLE Patient (id LONG PRIMARY KEY, nom STRING, prenom STRING, mail STRING, mdp STRING);";

	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}
