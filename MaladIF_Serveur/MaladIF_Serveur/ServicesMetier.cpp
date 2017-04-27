#include "stdafx.h"
#include "ServicesMetier.h"
#include <iostream>
#include <fstream>

ServicesMetier::ServicesMetier()
{

}


ServicesMetier::~ServicesMetier()
{

}

bool ServicesMetier::seConnecter(unsigned int id)
{
	// Recuperation de l'identifiant depuis un fichier txt
	/*ofstream os;
	if (os)
	{
		cout << "Ouverture du fichier test.txt" << endl;
		os << "Essai" << endl;
		os.close();
	}*/
	ifstream is("essai.txt", ios::in);
	if (is)
	{
		cout << "Ouverture du fichier reussie" << endl;
		string s;
		getline(is, s);
		cout << s << endl;
		is.close();
	}
	else {
		cout << "Erreur lors de l'ouverture du fichier" << endl;
	}
	// Comparaison avec l'id puis return true/false
	return false;
}

bool ServicesMetier::seDeconnecter()
{
	return false;
}

bool ServicesMetier::ajouterMaladie(string nom, string mots)
{
	return false;
}

bool ServicesMetier::modifierMaladie(string nom)
{
	return false;
}

bool ServicesMetier::supprimerMaladie(string nom)
{
	return false;
}

string ServicesMetier::recupererMaladie(string nom)
{
	return string();
}
