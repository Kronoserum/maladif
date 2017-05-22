#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include <vector> 
#include "Medecin.h"
#include "Entreprise.h"

#pragma once

class ServiceClient
{
public:

	bool ConnexionMedecin(int id);
	bool DeconnexionMedecin();

	int CreerDossierPatient(Patient p);
	Patient ConsulterDossierPatient(int id_patient);
	vector<Analyse> ConsulterAnalysesPatient(int id_patient);

	Analyse ConsulterResultatsAnalyse(int id_analyse);
	void ServiceClient::EffectuerAnalyse(string retSocket, string pathToGenome, int idPatient, int idMaladie, int idServeur);
	vector<Serveur> ConsulterDictionnaires();

	
	bool ConnexionEntreprise(int id);
	bool DeconnexionEntreprise();
	/*
	int ModifierDescriptionDictionnaire(string desc);
	int AjouterMaladie(Maladie m);
	int ModifierMaladie(Maladie m);
	int SupprimerMaladie(Maladie m);
	int ConsulterDictionnaire(int id_serveur);
	*/

	ServiceClient();
	~ServiceClient();

private: 
	Medecin * medecinCo;
	Entreprise * entrCo;
};

