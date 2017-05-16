// FenetreServeur.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Med'IF_Serveur.h"
#include "FenetreServeur.h"
#include "afxdialogex.h"


// Boîte de dialogue FenetreServeur

IMPLEMENT_DYNAMIC(FenetreServeur, CDialogEx)

FenetreServeur::FenetreServeur(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

FenetreServeur::~FenetreServeur()
{
}

void FenetreServeur::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FenetreServeur, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &FenetreServeur::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &FenetreServeur::OnBnClickedButton2)
END_MESSAGE_MAP()


// Gestionnaires de messages de FenetreServeur


void FenetreServeur::OnBnClickedButton1()
{
	listenerSock.Create(LISTENER_PORT);
	if (listenerSock.Listen())
	{
		AfxMessageBox(_T("Now listening !"));
	}
	else
	{
		AfxMessageBox(_T("Unable to listen !"));
		listenerSock.Close();
	}
}


void FenetreServeur::OnBnClickedButton2()
{
	//BOOL i =  listenerSock->ShutDown(2);
	listenerSock.Close();
	//if (i == 0) {
	//	AfxMessageBox(_T("Erreur lors de shutdown()"));
	//}
	AfxMessageBox(_T("Closing sockets"));
}
