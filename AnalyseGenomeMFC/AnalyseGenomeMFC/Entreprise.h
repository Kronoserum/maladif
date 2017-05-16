#pragma once

#include <string>

using namespace std;
class Entreprise
{
public:
	Entreprise();
	~Entreprise();

	int get_id();
	string get_nom();
	string get_description();

	void set_id(int id_in);
	void set_nom(string name_in);
	void set_description(string desc_in);

private:
	int id;
	string nom, description;

};

