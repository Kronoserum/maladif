#pragma once

#include "ListenerSocket.h"
// Boîte de dialogue FenetreServeur

class FenetreServeur : public CDialogEx
{
	DECLARE_DYNAMIC(FenetreServeur)

public:
	FenetreServeur(CWnd* pParent = NULL);   // constructeur standard
	virtual ~FenetreServeur();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

private:
	const int LISTENER_PORT = 8080;
	ListenerSocket listenerSock;
};
