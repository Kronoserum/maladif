#pragma once

#include <string>

using namespace std;
class Maladie
{
public:
	Maladie();
	~Maladie();

	long get_id();
	string get_nom();
	string get_typeMaladie();

	void set_id(long id_in);
	void set_nom(string name_in);
	void set_typeMaladie(string name_in);

private:
	long id;
	string nom, typeMaladie;
};

