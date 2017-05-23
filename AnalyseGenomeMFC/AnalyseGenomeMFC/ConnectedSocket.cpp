// ClientSocket.cpp : fichier d'implémentation
//
#pragma once

#include "stdafx.h"
#include "ConnectedSocket.h"
#include "ServiceClient.h"

using namespace std;

ConnectedSocket::ConnectedSocket()
{
	
}

ConnectedSocket::~ConnectedSocket()
{
}

void ConnectedSocket::setOwner(CAnalyseGenomeMFCDlg * o)
{
	owner = o;
}


void ConnectedSocket::OnReceive(int nErrorCode)
{
	const int BUFF_LEN = 262000;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);

	if (nReceivedSize <= 0)
		return;
	szBuff[nReceivedSize] = '\0';

	string data(szBuff);
	if (data.substr(0, data.find(":")).compare("returnMots")==0)
	{
		ServiceClient m;
		//AfxMessageBox((CString)data.substr(data.find(":") + 1).c_str());
		CString pathToGenome("genomeMalade.txt");
		m.EffectuerAnalyse(data.substr(data.find(":")+1), pathToGenome, owner->idPatient, owner->idMaladie);
		owner->texteConsole.Insert(owner->texteConsole.GetLength(), (CString)data.c_str());
		owner->UpdateData(false);
	}
	else if (data.compare("return:connected\r\n") == 0)
	{
		owner->entrepriseConnected = 1;
		owner->texteConsole.Insert(owner->texteConsole.GetLength(), (CString)data.substr(data.find(":")+1).c_str());
		owner->UpdateData(false);
	}
	else
	{
		owner->texteConsole.Insert(owner->texteConsole.GetLength(), (CString)data.c_str());
		owner->UpdateData(false);
	}

	CAsyncSocket::OnReceive(nErrorCode);
}

void ConnectedSocket::OnConnect(int nErrorCode)
{
	CAsyncSocket::OnConnect(nErrorCode);
}

void ConnectedSocket::OnSend(int nErrorCode)
{
	
}
