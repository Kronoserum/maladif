// ClientSocket.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ConnectedSocket.h"

#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

ConnectedSocket::ConnectedSocket()
{

}

ConnectedSocket::~ConnectedSocket()
{
}

void ConnectedSocket::OnReceive(int nErrorCode)
{
	//--------------------------------------------------------------------Debut de la reception
	const int BUFF_LEN = 256;
	char *szBuff = new char[BUFF_LEN]; // Initialisation du buffer
	int nReceivedSize = Receive(szBuff, BUFF_LEN); // reception des donnees
	if (nReceivedSize == SOCKET_ERROR)// Safety check
		return;
	szBuff[nReceivedSize] = '\0'; // Ajout du caractere de fin de chaine
	string str(szBuff);	// conversion de la commande au format string
	free(szBuff); // liberation du buffer

	//------------------------------------------------------------------------------Traitement
	string strResponse;

	if (str.find(":") == string::npos)
	{
		strResponse = "error:format de commande incorrect.\r\n";
	}
	else {
		string requete = str.substr(0, str.find(":"));
		string arguments = str.substr(str.find(":") + 1, str.size());
		arguments = arguments.substr(0, arguments.find(":"));
		if (requete.compare("connexion")==0)
		{
			bool res = s.seConnecter(stoi(arguments)); // arguments doit etre un nombre entier
			if (res)
			{
				strResponse = "return:connected\r\n";
			}
			else
			{
				strResponse = "return:not connected\r\n";
			}
		}
		else if (requete.compare("disconnect") == 0)
		{
			this->Close();
		}
		else if (requete.compare("recupererMetaDonnees")==0)
		{
			strResponse = "return:";
			strResponse.append(s.recupererMetaDonnees());
			strResponse.append("\r\n");
		}
		else if (requete.compare("ajouterMaladie") == 0)
		{
			string nom = arguments.substr(0, arguments.find(","));
			string mots = arguments.substr(nom.size()+1, arguments.size()-nom.size());
			int ret = s.ajouterMaladie(nom, mots);
			if (ret == 1)
			{
				strResponse = "return:maladie ajoutee\r\n";
			}
			else if (ret == 0)
			{
				strResponse = "return:maladie deja presente, annulation.\r\n";
			}
			else
			{
				strResponse = "error:erreur lors de l'ouverture d'un fichier\r\n";
			}
		}
		else if (requete.compare("modifierMaladie")==0)
		{
			string nom = arguments.substr(0, arguments.find(","));
			string mots = arguments.substr(nom.size()+1, arguments.size() - nom.size());
			bool ret = s.modifierMaladie(nom, mots);
			if (ret)
			{
				strResponse = "return:maladie modifiee\r\n";
			}
			else
			{
				strResponse = "error:operation annulée\r\n";
			}
		}
		else if (requete.compare("supprimerMaladie")==0)
		{
			int i = s.supprimerMaladie(arguments);
			if (i == 1) {
				strResponse = "return:maladie supprimee\r\n";
			}
			else if (i == 0) {
				strResponse = "return:maladie introuvable\r\n";
			}
			else {
				strResponse = "error:erreur lors de l'ouverture d'un fichier\r\n";
			}
		}
		else if (requete.compare("recupererMaladie") == 0)
		{
			strResponse = "returnMots:";
			strResponse.append(s.recupererMaladie(arguments));
			strResponse.append("\r\n");
		}
		else if (requete.compare("recupererNomsToutesMaladies")==0)
		{
			strResponse = "return:";
			strResponse.append(s.recupererNomsToutesMaladies());
			strResponse.append("\r\n");
		}
		else if (requete.compare("modifierMetaDonnees") == 0)
		{
			bool ret = s.modifierMetaDonnees(arguments);
			if (ret)
			{
				strResponse = "return:metadonnees modifiee\r\n";
			}
			else
			{
				strResponse = "error:operation annulée\r\n";
			}
		}
		else
		{
			strResponse = "error:requete inconnue\r\n";
		}
	}
	

	//---------------------------------------------------------------------Envoi de la réponse
	int nSentBytes = 0;
	const char* pszBuff = strResponse.c_str();
	int nResponseSize = strResponse.length();

	while (nSentBytes < nResponseSize)
	{
		nSentBytes = Send(pszBuff, nResponseSize);
		nResponseSize = nResponseSize - nSentBytes;
		pszBuff = pszBuff + nSentBytes;
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
