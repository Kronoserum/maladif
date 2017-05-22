// ClientSocket.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ConnectedSocket.h"

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
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	// Safety check
	if (nReceivedSize <= 0)
		return;
	szBuff[nReceivedSize] = '\0';


	//------------------------------------------------------------------------------Traitement
	//AfxMessageBox((CString)szBuff);
	string str = string(szBuff);	// commande au format string
	
	//CString c (str.c_str());
	//AfxMessageBox(c);

	string strResponse;
	if (str.find(":") == string::npos)
	{
		strResponse = "Erreur : format de commande incorrect.\r\n";
	}
	else {
		string requete = str.substr(0, str.find(":"));
		CString c(requete.c_str());
		//AfxMessageBox(c);
		if (requete.compare("disconnect") == 0)
		{
			//AfxMessageBox(_T("J'ai recu le message bonjour"));
			//strResponse = "Bonjour a toi !\r\n";
			AfxMessageBox(_T("Déconnexion..."));
			this->Close();
		}
		else
		{	
			AfxMessageBox(_T("Je ne connais pas cette requete"));
			strResponse = "hello\r\n";
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
