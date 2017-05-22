#include "stdafx.h"
#include "ServiceClient.h"

#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include "Maladie.h"
#include "PatientDADatabase.h"
#include "AnalyseDADatabase.h"
#include <vector>
#include "Database.h"
#include "ServeurDADatabase.h"
#include "MedecinDADatabase.h"
#include "EntrepriseDADatabase.h"

/*  ---------- Services Médecin ---------- */ 

bool ServiceClient::ConnexionMedecin(int id) {
	MedecinDADatabase mda;
	Medecin medecin;
	mda.read_medecin(medecin, id);

	medecinCo = &medecin;

	return true;
}

bool ServiceClient::DeconnexionMedecin() {
	medecinCo = NULL;
	return true;
}

int ServiceClient::CreerDossierPatient(Patient p) {

	PatientDADatabase pda;
	int codeW = pda.write_patient(p);
	return codeW;
}


int ServiceClient::ConsulterDossierPatient(Patient p, int id_patient) {
	PatientDADatabase pda;
	int codeR = pda.read_patient(p, id_patient);
	return codeR;
}

vector<Analyse> ServiceClient::ConsulterAnalysesPatient(int id_patient) {
	PatientDADatabase pda;
	Patient patient_a_analyser;
	int codeRP = pda.read_patient(patient_a_analyser, id_patient);
	AnalyseDADatabase ada;
	vector<Analyse> vecteurAnalyses = ada.read_analyse_patient(patient_a_analyser);
	return vecteurAnalyses;
}

Analyse ServiceClient::ConsulterResultatsAnalyse(int id_analyse) {
	AnalyseDADatabase ada;
	Analyse analyse;
	ada.read_analyse(analyse, id_analyse);

	return analyse;
}

void ServiceClient::EffectuerAnalyse() {

}

vector<Serveur> ServiceClient::ConsulterDictionnaires() {
	ServeurDADatabase sda;
	Serveur serveur;
	vector<Serveur> vecteurServeurs = sda.read_all_servers();
	return vecteurServeurs;
}


/*  ---------- Services Entreprise ---------- */

bool ServiceClient::ConnexionEntreprise(int id) {
	EntrepriseDADatabase eda;
	Entreprise entreprise;
	eda.read_entreprise(entreprise, id);

	entrCo = &entreprise;

	return true;
}

bool ServiceClient::DeconnexionEntreprise() {
	entrCo = NULL;
}

int ModifierDescriptionDictionnaire(string desc) {
		
}

int AjouterMaladie(Maladie m){

}

int ModifierMaladie(Maladie m) {

}

int SupprimerMaladie(Maladie m) {

}

Serveur ConsulterDictionnaire(int id_serveur) {
	ServeurDADatabase sda;
	Serveur se;
	sda.read_serveur(se, id_serveur);
	
	return se;
}

ServiceClient::ServiceClient() {

}


ServiceClient::~ServiceClient() {

}
