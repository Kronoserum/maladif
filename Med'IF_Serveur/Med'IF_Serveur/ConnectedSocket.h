#pragma once

#include <string>
#include "Services.h"

class ConnectedSocket : public CAsyncSocket
{
public:
	ConnectedSocket();
	virtual ~ConnectedSocket();
	virtual void OnReceive(int nErrorCode);

private:
	Services s;
};
