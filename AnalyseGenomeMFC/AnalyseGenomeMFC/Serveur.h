#pragma once

#include <string>

using namespace std;
class Serveur
{
public:
	Serveur();
	~Serveur();
	void set_id(long id_in);
	void set_IPServeur(string ip_in);
	void set_description(string desc_in);
	void set_idEntreprise(long entr_in);

	long get_id();
	string get_IPServeur();
	string get_description();
	long get_idEntreprise();
private:
	long id;
	string IPServeur, description;
	long idEntreprise;
};

