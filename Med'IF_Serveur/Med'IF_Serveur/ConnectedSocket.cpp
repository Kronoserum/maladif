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
	const int BUFF_LEN = 256;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	szBuff[nReceivedSize] = '\0';
	CString str;
	AfxMessageBox((CString)szBuff);
	if (nReceivedSize <= 0)
		return;

	string strResponse = "hello\r\n";



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
