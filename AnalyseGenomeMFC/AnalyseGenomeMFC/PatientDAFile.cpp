#include "stdafx.h"
#include "PatientDAFile.h"


PatientDAFile::PatientDAFile()
{
}

PatientDAFile::~PatientDAFile()
{
}

int PatientDAFile::write_patient(Patient patient)
{
	patient_file.open(patient_file_name, ios::app);

	patient_file << patient.get_id() << SEP
		<< patient.get_nom() << SEP
		<< patient.get_prenom() << SEP
		<< patient.get_mail() << SEP
		<< patient.get_mdp() << endl;

	patient_file.close();

	return 0;
}

int PatientDAFile::read_patient(Patient &patient, long id_in)
{
	int sep_pos = 0;
	string patient_record = "";

	patient.set_id(-1);

	patient_file.open(patient_file_name, ios::in);

	getline(patient_file, patient_record);

	while (patient.get_id() != id_in && !patient_file.eof())
	{
		sep_pos = patient_record.find_first_of(SEP);
		patient.set_id(stol(patient_record.substr(0, sep_pos)));
		patient_record = patient_record.substr(sep_pos + 1, patient_record.length());

		sep_pos = patient_record.find_first_of(SEP);
		patient.set_nom(patient_record.substr(0, sep_pos));
		patient_record = patient_record.substr(sep_pos + 1, patient_record.length());

		sep_pos = patient_record.find_first_of(SEP);
		patient.set_prenom(patient_record.substr(0, sep_pos));
		patient_record = patient_record.substr(sep_pos + 1, patient_record.length());

		sep_pos = patient_record.find_first_of(SEP);
		patient.set_mail(patient_record.substr(0, sep_pos));
		patient_record = patient_record.substr(sep_pos + 1, patient_record.length());

		sep_pos = patient_record.find_first_of(SEP);
		patient.set_mdp(patient_record.substr(0, sep_pos));

		getline(patient_file, patient_record);
	}

	patient_file.close();

	if (patient.get_id() == id_in)
		return 0;
	else
		return 1;
}
