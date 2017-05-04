#pragma once

// Cible de la commande ServerListener

class ListenerSocket : public CAsyncSocket
{
public:
	ListenerSocket();
	virtual ~ListenerSocket();
	virtual void OnAccept(int nErrorCode);
};


