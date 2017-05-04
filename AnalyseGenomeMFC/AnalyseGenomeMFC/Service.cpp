#include "stdafx.h"
#include "Service.h"

Service::Service()
{
}

Service::~Service()
{
}

void Service::create_patient(long id, string nom, string prenom, string mail, string mdp)
{
	Patient patient;

	patient.set_id(id);
	patient.set_nom(nom);
	patient.set_prenom(prenom);
	patient.set_mail(mail);
	patient.set_mdp(mdp);

	patient_DA_file.write_patient(patient);
}

void Service::create_patient(string patient_str)
{
	Patient patient;

	int sep_pos = 0;

	sep_pos = patient_str.find_first_of(SEP);
	patient.set_id(stol(patient_str.substr(0, sep_pos)));
	patient_str = patient_str.substr(sep_pos + 1, patient_str.length());

	sep_pos = patient_str.find_first_of(SEP);
	patient.set_nom(patient_str.substr(0, sep_pos));
	patient_str = patient_str.substr(sep_pos + 1, patient_str.length());

	sep_pos = patient_str.find_first_of(SEP);
	patient.set_prenom(patient_str.substr(0, sep_pos));
	patient_str = patient_str.substr(sep_pos + 1, patient_str.length());

	sep_pos = patient_str.find_first_of(SEP);
	patient.set_mail(patient_str.substr(0, sep_pos));
	patient_str = patient_str.substr(sep_pos + 1, patient_str.length());

	sep_pos = patient_str.find_first_of(SEP);
	patient.set_mdp(patient_str.substr(0, sep_pos));

	patient_DA_file.write_patient(patient);
}

string Service::find_patient(string id)
{
	Patient patient;
	string patient_str = "";

	if (patient_DA_file.read_patient(patient, stol(id)) == 0)
		patient_str =
			to_string(patient.get_id()) + "," +
			patient.get_nom() + "," +
			patient.get_prenom() + "," +
			patient.get_mail() + "," +
			patient.get_mdp();

	return patient_str;
}
