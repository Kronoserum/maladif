#include "stdafx.h"
#include "Serveur.h"
#include "ServeurDA.h"

#include <fstream>
#include <iostream>
using namespace std;

ServeurDA::ServeurDA()
{
}

ServeurDA::~ServeurDA()
{
}

int ServeurDA::getId()
{
	int idLocal = -1;
	ifstream is("Connexion.txt", ios::in);
	if (is)
	{
		string s;
		getline(is, s);
		idLocal = stoul(s, nullptr, 0);
		is.close();
	}
	else {
		cerr << "Erreur lors de l'ouverture du fichier de connexion" << endl;
	}
	return idLocal;
}

string ServeurDA::getMetadonnees()
{
	string meta;
	// Lire le fichier dictionnaire et extraire la premiere ligne
	ifstream is(nomDico, ios::in);
	if (is)
	{
		getline(is, meta);
		is.close();
	}
	else {
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return meta;
}

string ServeurDA::getNomsMaladies()
{
	string maladies;
	// Lire le fichier dictionnaire et extraire le noms des maladies
	ifstream is(nomDico, ios::in);
	if (is)
	{
		string tmp;
		getline(is, tmp); // Metadonnees
		int i = 0;
		while (getline(is, tmp))
		{
			if (i != 0)
			{
				maladies.append(",");
			}
			maladies.append(tmp.substr(0, tmp.find(":")));
			i++;
		}
		is.close();
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return maladies;
}

string ServeurDA::getMotsMaladie(string nomMaladie)
{
	string mots;
	// Lire le dictionnaire et extraire les mots associés à une maladie
	ifstream is(nomDico, ios::in);
	if (is)
	{
		string tmp;
		getline(is, tmp); // Metadonnees
		while (getline(is, tmp))
		{
			string name = tmp.substr(0, tmp.find(":"));
			if (name.compare(nomMaladie)==0)
			{
				// On a trouvé la bonne maladie
				mots = tmp.substr(tmp.find(":")+1, tmp.size() - tmp.find(":") - 1);
				is.close();
				return mots;
			}
		}
		is.close();
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return mots;
}

int ServeurDA::ajouterMaladie(string nom, string mots)
{
	if (mots[mots.length() - 1] != ';')
	{
		mots.append(";");
	}
	if (getMotsMaladie(nom).compare("") == 0)
	{
		ofstream os(nomDico, ios::out | ios::app);
		if(os)
		{
			os.seekp(ios::end);
			os << nom << ":" << mots << "\n";
			os.close();
		}
		else
		{
			cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
			return -1;
		}
		return 1;
	}
	return 0;
}

int ServeurDA::supprimerMaladie(string nom)
{
	string final;
	ifstream is(nomDico, ios::in);
	if (is)
	{
		string tmp;
		int resultat = 0;
		while (getline(is, tmp))
		{
			if (tmp.substr(0, tmp.find(":")).compare(nom) != 0)
			{
				final.append(tmp);
				final.append("\n");
			} 
			else
			{
				resultat = 1;
			}
		}
		is.close();

		ofstream os("Dictionnaire.txt", ios::out);
		if (os)
		{
			os << final;
			os.close();
			return resultat;
		}
		else
		{
			cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
		}
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return -1;
}

bool ServeurDA::mettreAJourMaladie(string nom, string mots)
{
	if (mots[mots.length() - 1] != ';')
	{
		mots.append(";");
	}
	ifstream is(nomDico, ios::in);
	if(is)
	{
		string final;
		string tmp;
		while (getline(is, tmp))
		{
			if (tmp.substr(0, tmp.find(":")).compare(nom) != 0)
			{
				final.append(tmp);
				final.append("\n");
			}
			else
			{
				final.append(tmp.substr(0, tmp.find(":")+1));
				final.append(mots);
				final.append("\n");
			}
		}
		is.close();

		ofstream os("Dictionnaire.txt", ios::out);
		if (os)
		{
			os << final;
			os.close();
			return true;
		}
		else
		{
			cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
		}
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return false;
}

bool ServeurDA::modifierMeta(string meta)
{
	ifstream is(nomDico, ios::in);
	if (is)
	{
		string met;
		getline(is, met);
		string tmp;
		string final;
		while (getline(is, tmp))
		{
			final.append(tmp);
			final.append("\n");
		}
		is.close();

		ofstream os("dictionnaire.txt", ios::out);
		if (os)
		{
			os << meta << "\n";
			os << final;
			os.close();
			return true;
		}
		else
		{
			cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
		}
	}
	else
	{
		cerr << "Erreur lors de l'ouverture du dictionnaire" << endl;
	}
	return false;
}
