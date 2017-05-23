#pragma once

#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include "Maladie.h"
#include "ConnectedSocket.h"
#include <vector> 
#include "Medecin.h"
#include "Entreprise.h"


class ServiceClient
{
public:

	int ConnexionMedecin(int id);
	bool DeconnexionMedecin();

	int CreerDossierPatient(Patient p);
	Patient ConsulterDossierPatient(int id_patient);
	vector<Analyse> ConsulterAnalysesPatient(int id_patient);

	Analyse ConsulterResultatsAnalyse(int id_analyse);
	void ServiceClient::EffectuerAnalyse(string &retSocket, CString pathToGenome, int idPatient, int idMaladie);
	vector<Serveur> ConsulterDictionnaires();

	//void ConsulterDictionnaires(Serveur s);

	void recupererMots(ConnectedSocket & s, string maladie);
	
	void ConnexionEntreprise(string id, ConnectedSocket & s);
	void DeconnexionEntreprise(ConnectedSocket & s);
	int ModifierDescriptionDictionnaire(string desc, ConnectedSocket & s);
	int AjouterMaladie(string nom, string desc, ConnectedSocket & s);
	void ConsulterDictionnaire(ConnectedSocket & s);
	void consulterMetaDonnees(ConnectedSocket & s);
	void SupprimerMaladie(string nom, ConnectedSocket & s);
	void ModifierMaladie(string nom, string desc, ConnectedSocket & socket);
	
	ServiceClient();
	~ServiceClient();

private: 
	Medecin * medecinCo;
	Entreprise * entrCo;
};

