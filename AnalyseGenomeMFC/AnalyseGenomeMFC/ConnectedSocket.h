#pragma once

#include <string>

#include "AnalyseGenomeMFCDlg.h"

class CAnalyseGenomeMFCDlg;

class ConnectedSocket : public CAsyncSocket
{
public:
	ConnectedSocket();
	virtual ~ConnectedSocket();
	void setOwner(CAnalyseGenomeMFCDlg *o);
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnSend(int nErrorCode);
private:
	CAnalyseGenomeMFCDlg *owner;
};
