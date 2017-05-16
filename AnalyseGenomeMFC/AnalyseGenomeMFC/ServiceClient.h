#include "Patient.h"
#include "Analyse.h"
#include "Serveur.h"

#pragma once

class ServiceClient
{
public:

	void Connexion();
	void Deconnexion();

	void CreerDossierPatient(Patient p);
	void SupprimerDossierPatient(Patient p);
	void ConsulterDossierPatient(Patient p);
	void ConsulterAnalysesPatient(Patient p);

	void ConsulterResultatsAnalyse(Analyse a);
	void EffectuerAnalyse();

	void ConsulterDictionnaires(Serveur s);

	ServiceClient();
	~ServiceClient();
};

