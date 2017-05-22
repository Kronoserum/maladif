#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include <vector> 

#pragma once

class ServiceClient
{
public:

	bool ConnexionMedecin(int id);
	bool DeconnexionMedecin();

	int CreerDossierPatient(Patient p);
	int SupprimerDossierPatient(Patient p);
	int ConsulterDossierPatient(Patient p, int id_patient);
	vector<Analyse> ConsulterAnalysesPatient(int id_patient);

	void ConsulterResultatsAnalyse(int id_analyse);
	void EffectuerAnalyse();

	void ConsulterDictionnaires(Serveur s);

	/*
	bool ConnexionEntreprise(int id);
	bool DeconnexionEntreprise();

	int ModifierDescriptionDictionnaire(string desc);
	int AjouterMaladie(Maladie m);
	int ModifierMaladie(Maladie m);
	int SupprimerMaladie(Maladie m);
	int ConsulterDictionnaire(int id_serveur);
	*/

	ServiceClient();
	~ServiceClient();
};

