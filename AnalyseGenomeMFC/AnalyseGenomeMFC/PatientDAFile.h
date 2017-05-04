#pragma once
#include <fstream>
#include <iostream>

#include "PatientDA.h"
#include "Common.h"

using namespace std;

class PatientDAFile : public PatientDA
{
private:
	const char *patient_file_name = "patient.txt";
	fstream patient_file;

public:
	PatientDAFile();
	~PatientDAFile();

	int write_patient(Patient patient);
	int read_patient(Patient &patient, long id_in);
};
