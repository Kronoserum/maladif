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

	/*On ajoute une maladie si elle n'existe pas déjà. 
		Retourne 1 si tout s'est bien passé
		Retourne -1 si le fichier n'a pas pu être ouvert
		Retourne 0 si la maladie existe déjà
	*/
	int ajouterMaladie(string nom, string mots);

	/*On supprime une maladie si elle est présente
		Retourne 1 si ca a marché
		Retourne 0 si la maladie n'a pas été trouvée
		Retourne -1 si il y a eu une erreur
	*/
	int supprimerMaladie(string nom);

	bool mettreAJourMaladie(string nom, string mots);

private:
	string nomDico = "dictionnaire.txt";
};