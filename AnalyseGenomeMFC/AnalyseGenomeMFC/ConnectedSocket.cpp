// ClientSocket.cpp : fichier d'implémentation
//
#pragma once

#include "stdafx.h"
#include "ConnectedSocket.h"

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
	const int BUFF_LEN = 2048;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);

	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize] = '\0';
	CString data(szBuff);
	owner->texteConsole.Insert(owner->texteConsole.GetLength(), data);

	CAsyncSocket::OnReceive(nErrorCode);
}

void ConnectedSocket::OnConnect(int nErrorCode)
{
	CAsyncSocket::OnConnect(nErrorCode);
}

void ConnectedSocket::OnSend(int nErrorCode)
{
	
}
