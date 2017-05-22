#include "stdafx.h"
#include "AnalyseDADatabase.h"

AnalyseDADatabase::AnalyseDADatabase()
{
}

AnalyseDADatabase::~AnalyseDADatabase()
{
}

void AnalyseDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int AnalyseDADatabase::write_analyse(Analyse analyse)
{
	int code;
	char *error;

	string sqlInsertStr = "INSERT INTO Analyse (date,resultat,idMaladie,idMedecin,idPatient,idServeur) VALUES('" 
		+ analyse.get_Date() + "', '"
		+ to_string(analyse.get_resultat()) + "', '"
		+ to_string(analyse.get_IdMaladie()) + "', '"
		+ to_string(analyse.get_IdMedecin()) + "', '"
		+ to_string(analyse.get_IdPatient()) + "', '"
		+ to_string(analyse.get_idServeur()) + "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_analyse): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int AnalyseDADatabase::read_analyse(Analyse &analyse, int id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Analyse WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_analyse): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		analyse.set_id(stoi(results[0 + columns]));
		analyse.set_date(results[1 + columns]);
		analyse.set_resultat(stoi(results[2 + columns]));
		analyse.set_idMaladie(stoi(results[3 + columns]));
		analyse.set_idMedecin(stoi(results[4 + columns]));
		analyse.set_idPatient(stoi(results[5 + columns]));
		analyse.set_idServeur(stoi(results[5 + columns]));

	}
	
	sqlite3_free_table(results);

	return code;
}

vector<Analyse> AnalyseDADatabase::read_analyse_patient(Patient patient)
{
	vector<Analyse>retour;

	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Analyse WHERE idPatient =" + to_string(patient.get_id()) + ";";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_analyse): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			Analyse analyse;
			analyse.set_id(stoi(results[i * columns + 0]));
			analyse.set_date(results[i * columns + 1]);
			analyse.set_resultat(stoi(results[i * columns + 2]));
			analyse.set_idMaladie(stoi(results[i * columns + 3]));
			analyse.set_idMedecin(stoi(results[i * columns + 4]));
			analyse.set_idPatient(stoi(results[i * columns + 5]));
			analyse.set_idServeur(stoi(results[i * columns + 6]));

			retour.push_back(analyse);
		}



	}

	sqlite3_free_table(results);

	return retour;
}

