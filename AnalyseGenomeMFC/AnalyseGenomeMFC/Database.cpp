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

	const char *sqlCreateTable = "CREATE TABLE Patient (id INTEGER PRIMARY KEY AUTOINCREMENT, nom STRING, prenom STRING, mail STRING, mdp STRING);";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	sqlCreateTable = "CREATE TABLE Medecin (id INTEGER PRIMARY KEY AUTOINCREMENT, nom STRING, prenom STRING, adresse STRING, salaire REAL, mdp STRING);";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	sqlCreateTable = "CREATE TABLE Entreprise (id INTEGER PRIMARY KEY AUTOINCREMENT, nom STRING, description STRING);";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	sqlCreateTable = "CREATE TABLE Serveur (id INTEGER PRIMARY KEY AUTOINCREMENT, description STRING, ipServeur STRING, idEntreprise INTEGER, FOREIGN KEY(idEntreprise ) REFERENCES Entreprise(id));";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	sqlCreateTable = "CREATE TABLE Maladie (id INTEGER PRIMARY KEY AUTOINCREMENT, nom STRING, typeMaladie STRING);";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	sqlCreateTable = "CREATE TABLE Analyse (id INTEGER PRIMARY KEY AUTOINCREMENT, date STRING, resultat INTEGER, idMaladie INTEGER,  idMedecin INTEGER,  idPatient INTEGER,  idServeur INTEGER, FOREIGN KEY(idServeur) REFERENCES Serveur(id),FOREIGN KEY(idMaladie) REFERENCES Maladie(id),FOREIGN KEY(idPatient) REFERENCES Patient(id),FOREIGN KEY(idMedecin) REFERENCES Medecin(id));";
	code = sqlite3_exec(database, sqlCreateTable, NULL, NULL, &error);
	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (create_tables): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}
	