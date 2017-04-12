#pragma once
class Patient
{
public:
	void toString();

	Patient();
	~Patient();
private:
	unsigned int idPatient;
	string nom, prenom, adresse, dateNaissance;
};

