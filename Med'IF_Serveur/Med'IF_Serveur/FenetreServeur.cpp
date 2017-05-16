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
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void FenetreServeur::OnBnClickedButton2()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}
