#pragma once

#include <string>

using namespace std;
class Serveur
{
public:
	Serveur();
	~Serveur();
	Serveur(string ip_in, string desc_in, int ent_in);

	void set_id(int id_in);
	void set_IPServeur(string ip_in);
	void set_description(string desc_in);
	void set_idEntreprise(int entr_in);

	int get_id();
	string get_IPServeur();
	string get_description();
	int get_idEntreprise();
private:
	int id;
	string IPServeur, description;
	int idEntreprise;
};

