#pragma once


// Boîte de dialogue AccueilEntreprise

class AccueilEntreprise : public CDialogEx
{
	DECLARE_DYNAMIC(AccueilEntreprise)

public:
	AccueilEntreprise(CWnd* pParent = NULL);   // constructeur standard
	virtual ~AccueilEntreprise();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEDIF_SERVEUR_ACCUEIL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString metadonnees;
};
