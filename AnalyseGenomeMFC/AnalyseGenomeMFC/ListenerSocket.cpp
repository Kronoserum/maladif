// ServerListener.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenomeMFC.h"
#include "ListenerSocket.h"
#include "ConnectedSocket.h"

// ServerListener

ListenerSocket::ListenerSocket()
{
}

ListenerSocket::~ListenerSocket()
{
}

void ListenerSocket::OnAccept(int nErrorCode)
{
	ConnectedSocket* pConnectedSock = new ConnectedSocket();

	CString strPeerName;
	UINT uiPort;

	if (Accept(*pConnectedSock))
	{
		pConnectedSock->GetPeerName(strPeerName, uiPort);
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
