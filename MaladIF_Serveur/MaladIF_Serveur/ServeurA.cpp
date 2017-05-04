#include <string>

#include "stdafx.h"
#include "Serveur.h"

using namespace std;

Serveur::Serveur(unsigned int id, string metadonneesS)
{
	idEntreprise = id;
	metadonnees = metadonneesS;
}

unsigned int Serveur::getId()
{
	return idEntreprise;
}

string Serveur::getMetadonnees()
{
	return metadonnees;
}


Serveur::~Serveur()
{
}
