#include "stdafx.h"
#include "ServiceClient.h"

#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include "Maladie.h"
#include "PatientDADatabase.h"
#include "Database.h"

/*  ---------- Services Médecin ---------- */ 

bool ServiceClient::ConnexionMedecin(int id) {
	return false;
}

bool ServiceClient::DeconnexionMedecin() {
	return false;
}

int ServiceClient::CreerDossierPatient(Patient p) {
	PatientDADatabase pda;
	Database db;
	db.open_database();

	pda.set_database(db.get_database());

	int codeW = pda.write_patient(p);
	return codeW;
}

int ServiceClient::SupprimerDossierPatient(Patient p) {
	//A implémenter dans DA
	return 0;
}

int ServiceClient::ConsulterDossierPatient(Patient p, int id_patient) {
	PatientDADatabase pda;
	int codeR = pda.read_patient(p, id_patient);
	return codeR;
}

void ServiceClient::ConsulterAnalysesPatient(int id_patient) {

}

void ServiceClient::ConsulterResultatsAnalyse(int id_analyse) {

}

void ServiceClient::EffectuerAnalyse() {

}

void ServiceClient::ConsulterDictionnaires(Serveur s) {

}


/*  ---------- Services Entreprise ---------- */
/*
bool ServiceClient::ConnexionEntreprise(int id) {

}

bool ServiceClient::DeconnexionEntreprise() {

}

int ModifierDescriptionDictionnaire(string desc) {
		
}

int AjouterMaladie(Maladie m){

}

int ModifierMaladie(Maladie m) {

}

int SupprimerMaladie(Maladie m) {

}

int ConsulterDictionnaire(int id_serveur) {

}
*/

ServiceClient::ServiceClient() {

}


ServiceClient::~ServiceClient() {

}
