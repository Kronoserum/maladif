#pragma once

#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"
#include "Maladie.h"
#include "ConnectedSocket.h"
#include <vector> 


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
	
	
	void ConnexionEntreprise(string id, ConnectedSocket & s);
	bool DeconnexionEntreprise(ConnectedSocket & s);

	int ModifierDescriptionDictionnaire(string desc, ConnectedSocket & s);
	int AjouterMaladie(Maladie m, ConnectedSocket & s);
	int ModifierMaladie(Maladie m, ConnectedSocket & s);
	int SupprimerMaladie(Maladie m, ConnectedSocket & s);
	int ConsulterDictionnaire(int id_serveur, ConnectedSocket & s);

	CString RetourSocket(CString retour);
	
	ServiceClient();
	~ServiceClient();
};

