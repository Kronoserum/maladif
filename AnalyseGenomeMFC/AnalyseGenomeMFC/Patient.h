#pragma once

#include <string>

using namespace std;

class Patient
{
private:
	int id;
	string nom;
	string prenom;
	string mail;
	string mdp;

public:
	Patient();
	~Patient();
	Patient(string nom_in,string pre_in, string mail_in, string mdp_in);

	void set_id(int id_in);
	void set_nom(string nom_in);
	void set_prenom(string prenom_in);
	void set_mail(string mail_in);
	void set_mdp(string mdp_in);

	int get_id();
	string get_nom();
	string get_prenom();
	string get_mail();
	string get_mdp();
};
