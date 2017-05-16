#pragma once#pragma once

#include <string>

using namespace std;

class Analyse
{
public:
	Analyse();
	~Analyse();


	long get_id();
	int get_resultat();
	string get_Date();
	long get_IdMedecin();
	long get_IdPatient();
	long get_IdMaladie();
	long get_idServeur();

	void set_id(long id_in);
	void set_resultat(int res_in);
	void set_date(string date_in);
	void set_idMedecin(long id_in);
	void set_idPatient(long id_in);
	void set_idMaladie(long id_in);
	void set_idServeur(long id_in);

	

private:
	long id;
	int resultat;
	string dateAnalyse;
	long idMedecin;
	long idMaladie;
	long idPatient;
	long idServeur;
	
};



