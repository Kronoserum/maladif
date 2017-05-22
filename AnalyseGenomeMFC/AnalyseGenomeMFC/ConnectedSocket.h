#pragma once

#include <string>

class ConnectedSocket : public CAsyncSocket
{
public:
	ConnectedSocket();
	virtual ~ConnectedSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
};
