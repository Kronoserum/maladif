#pragma once

#include <string>

using namespace std;

class Medecin
{
private:
	int id;
	string nom;
	string prenom;
	string adresse;
	string mdp;
	double salaire;

public:
	Medecin();
	~Medecin();

	void set_id(int id_in);
	void set_nom(string nom_in);
	void set_prenom(string prenom_in);
	void set_adresse(string mail_in);
	void set_mdp(string mdp_in);
	void set_salaire(double sal_in);


	int get_id();
	string get_nom();
	string get_prenom();
	string get_adresse();
	string get_mdp();
	double get_salaire();
};
