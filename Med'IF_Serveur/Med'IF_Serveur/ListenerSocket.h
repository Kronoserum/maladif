#pragma once

// Cible de la commande ServerListener

#include "ConnectedSocket.h"

class ListenerSocket : public CAsyncSocket
{
public:
	ListenerSocket();
	virtual ~ListenerSocket();
	virtual void OnAccept(int nErrorCode);
	virtual void Close();

private:
	ConnectedSocket* pConnectedSock;
};
