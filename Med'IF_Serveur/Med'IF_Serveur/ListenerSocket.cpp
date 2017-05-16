// ServerListener.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ConnectedSocket.h"
#include "ListenerSocket.h"


// ServerListener

ListenerSocket::ListenerSocket()
{

}

ListenerSocket::~ListenerSocket()
{

}

void ListenerSocket::OnAccept(int nErrorCode)
{
	pConnectedSock = new ConnectedSocket();

	CString strPeerName;
	UINT uiPort;

	if (Accept(*pConnectedSock))
	{
		pConnectedSock->GetPeerName(strPeerName, uiPort);
		AfxMessageBox(_T("Connecté au serveur"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void ListenerSocket::Close()
{
	pConnectedSock->Close();
	CAsyncSocket::Close();
}
