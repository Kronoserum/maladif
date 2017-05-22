#pragma once

#include <string>
#include <list>
using namespace std;

class ServeurDA
{
public:
	ServeurDA();
	~ServeurDA();

	int getId();
	string getMetadonnees();
	string getNomsMaladies();
	string getMotsMaladie(string nomMaladie);

	/*On ajoute une maladie si elle n'existe pas d�j�. 
		Retourne 1 si tout s'est bien pass�
		Retourne -1 si le fichier n'a pas pu �tre ouvert
		Retourne 0 si la maladie existe d�j�
	*/
	int ajouterMaladie(string nom, string mots);

	/*On supprime une maladie si elle est pr�sente
		Retourne 1 si ca a march�
		Retourne 0 si la maladie n'a pas �t� trouv�e
		Retourne -1 si il y a eu une erreur
	*/
	int supprimerMaladie(string nom);

	bool mettreAJourMaladie(string nom, string mots);

private:
	string nomDico = "dictionnaire.txt";
};