#pragma once

#include <string>

#include "Patient.h"
#include "PatientDAFile.h"
#include "Common.h"

using namespace std;

class Service
{
private:
	PatientDAFile patient_DA_file;

public:
	Service();
	~Service();

	void create_patient(long id, string nom, string prenom, string mail, string mdp);
	void create_patient(string patient_str);
	string find_patient(string id);
};
