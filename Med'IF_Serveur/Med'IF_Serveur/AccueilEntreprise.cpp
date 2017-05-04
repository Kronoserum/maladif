// AccueilEntreprise.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "Med'IF_Serveur.h"
#include "AccueilEntreprise.h"
#include "afxdialogex.h"


// Bo�te de dialogue AccueilEntreprise

IMPLEMENT_DYNAMIC(AccueilEntreprise, CDialogEx)

AccueilEntreprise::AccueilEntreprise(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MEDIF_SERVEUR_ACCUEIL, pParent)
	, metadonnees(_T(""))
{

}

AccueilEntreprise::~AccueilEntreprise()
{
}

void AccueilEntreprise::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, metadonnees);
}


BEGIN_MESSAGE_MAP(AccueilEntreprise, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT, &AccueilEntreprise::OnEnChangeEdit)
	ON_BN_CLICKED(IDC_BUTTON1, &AccueilEntreprise::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &AccueilEntreprise::OnBnClickedButton2)
END_MESSAGE_MAP()


// Gestionnaires de messages de AccueilEntreprise


void AccueilEntreprise::OnEnChangeEdit()
{
	// TODO:  S'il s'agit d'un contr�le RICHEDIT, le contr�le ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajout� au masque gr�ce � l'op�rateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contr�le
}


void AccueilEntreprise::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
	UpdateData(true);

}


void AccueilEntreprise::OnBnClickedButton2()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
	UpdateData(false);
}
