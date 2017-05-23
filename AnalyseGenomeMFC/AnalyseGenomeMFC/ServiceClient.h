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
	void ServiceClient::EffectuerAnalyse(string retSocket, string pathToGenome, int idPatient, int idMaladie, int idServeur);
	vector<Serveur> ConsulterDictionnaires();
	
	
	void ConnexionEntreprise(string id, ConnectedSocket & s);
	void DeconnexionEntreprise(ConnectedSocket & s);

	int ModifierDescriptionDictionnaire(string desc, ConnectedSocket & s);
	int AjouterMaladie(Maladie m, ConnectedSocket & s);
	Serveur ConsulterDictionnaire(int id_serveur);

	CString RetourSocket(CString retour);
	
	ServiceClient();
	~ServiceClient();

private: 
	Medecin * medecinCo;
	Entreprise * entrCo;
};

