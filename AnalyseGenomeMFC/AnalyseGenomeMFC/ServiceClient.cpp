#pragma once

#include "stdafx.h"
#include "ServiceClient.h"

#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include "Maladie.h"
#include "PatientDADatabase.h"
#include "AnalyseDADatabase.h"
#include "MaladieDADatabase.h"
#include <vector>
#include "Database.h"
#include "ServeurDADatabase.h"
#include "MedecinDADatabase.h"
#include "EntrepriseDADatabase.h"
#include "wumanber.h"
#include "fstream"
#include "iostream"

/*  ---------- Services Médecin ---------- */ 

int ServiceClient::ConnexionMedecin(int id) {
	MedecinDADatabase mda;
	Medecin medecin;
	int code = mda.read_medecin(medecin, id);

	medecinCo = &medecin;

	return code;
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


Patient ServiceClient::ConsulterDossierPatient(int id_patient) {
	PatientDADatabase pda;
	Patient patient_a_consulter;
	int codeR = pda.read_patient(patient_a_consulter, id_patient);
	return patient_a_consulter;
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

void ServiceClient::EffectuerAnalyse(string retSocket,CString pathToGenome, int idPatient, int idMaladie) {
	clock_t start;
	double duration;
	unsigned int capacity;

	capacity = (int) retSocket.capacity();
	start = clock();

	WuManber wu;

	vector<string> pattern = wu.Convert(retSocket);
	wu.Init(pattern);

	int resultat;

	ifstream text(pathToGenome);
	while (text>>retSocket) {
		resultat = wu.Search(retSocket);
	}

	string date = "23/05";
	
	int idMed = medecinCo->get_id();

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;


	Analyse ana(resultat, date, idMed, idPatient, idMaladie, 1);
	AnalyseDADatabase ada;
	ada.write_analyse(ana);

}

vector<Serveur> ServiceClient::ConsulterDictionnaires() {
	ServeurDADatabase sda;
	Serveur serveur;
	vector<Serveur> vecteurServeurs = sda.read_all_servers();
	return vecteurServeurs;
}


/*  ---------- Services Entreprise ---------- */

void ServiceClient::recupererMots(ConnectedSocket & s, string maladie)
{
	string commande = "recupererMaladie:";
	commande.append(maladie);
	commande.append(":");
	s.Send(commande.c_str(), strlen(commande.c_str()));
	AfxMessageBox(_T("Fin de recuperer mots"));
}

void ServiceClient::ConnexionEntreprise(string id, ConnectedSocket & s) {
	string commande("connexion:");
	commande.append(id);
	commande.append(":");
	s.Send(commande.c_str(), commande.length());
}

void ServiceClient::DeconnexionEntreprise(ConnectedSocket & s) {
	string commande("disconnect:");
	s.Send(commande.c_str(), commande.length());
}

int ServiceClient::ModifierDescriptionDictionnaire(string desc, ConnectedSocket & s)
{
	string commande("modifierMetaDonnees:");
	commande.append(desc);
	commande.append(":");
	s.Send(commande.c_str(), commande.length());
	return 0;
}

int ServiceClient::AjouterMaladie(string nom, string desc, ConnectedSocket & s)
{
	string commande("ajouterMaladie:");
	commande.append(nom);
	commande.append(",");
	commande.append(desc);
	s.Send(commande.c_str(), commande.length());
	return 0;
}

void ServiceClient::ConsulterDictionnaire(ConnectedSocket & s)
{
	string commande("recupererNomsToutesMaladies:");
	s.Send(commande.c_str(), commande.length());
}

void ServiceClient::consulterMetaDonnees(ConnectedSocket & s)
{
	string commande("recupererMetaDonnees:");
	s.Send(commande.c_str(), commande.length());
}

void ServiceClient::SupprimerMaladie(string nom, ConnectedSocket & s)
{
	string commande("supprimerMaladie:");
	commande.append(nom);
	s.Send(commande.c_str(), commande.length());
}

void ServiceClient::ModifierMaladie(string nom, string desc, ConnectedSocket & socket)
{
	string commande("modifierMaladie:");
	commande.append(nom);
	commande.append(",");
	commande.append(desc);
	socket.Send(commande.c_str(), commande.length());
}

/*Serveur ServiceClient::ConsulterDictionnaire(int id_serveur) {
	ServeurDADatabase sda;
	Serveur se;
	sda.read_serveur(se, id_serveur);
	
	return se;
}*/

ServiceClient::ServiceClient()
{
	
}

ServiceClient::~ServiceClient() {

}
