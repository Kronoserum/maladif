#pragma once

#include "Patient.h"

class PatientDA
{
public:
	virtual int write_patient(Patient patient) = 0;
	virtual int read_patient(Patient &patient, long id_in) = 0;
};
