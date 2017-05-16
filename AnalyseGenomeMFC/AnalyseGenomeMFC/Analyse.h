#pragma once#pragma once

#include <string>

using namespace std;

class Analyse
{
public:
	Analyse();
	~Analyse();


	int get_id();
	int get_resultat();
	string get_Date();
	int get_IdMedecin();
	int get_IdPatient();
	int get_IdMaladie();
	int get_idServeur();

	void set_id(int id_in);
	void set_resultat(int res_in);
	void set_date(string date_in);
	void set_idMedecin(int id_in);
	void set_idPatient(int id_in);
	void set_idMaladie(int id_in);
	void set_idServeur(int id_in);

	

private:
	int id;
	int resultat;
	string dateAnalyse;
	int idMedecin;
	int idMaladie;
	int idPatient;
	int idServeur;
	
};



