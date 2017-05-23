
// AnalyseGenomeMFCDlg.h : fichier d'en-t�te
//

#pragma once
#include "ConnectedSocket.h"
#include <string>

class ConnectedSocket;

// bo�te de dialogue CAnalyseGenomeMFCDlg
class CAnalyseGenomeMFCDlg : public CDialogEx
{
// Construction
public:
	CAnalyseGenomeMFCDlg(CWnd* pParent = NULL);	// constructeur standard

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYSEGENOMEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Impl�mentation
protected:
	HICON m_hIcon;

	// Fonctions g�n�r�es de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	void OnOK(void);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartserver();
	afx_msg void OnBnClickedShutdownserver();
	afx_msg void OnBnClickedDatabase();

	

private:
	ConnectedSocket *socket;
	bool socketLaunched = false;


public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedStaticAffichage();
	// r�cup�re la ligne de commande fournie dans le champ
	CString commande;
	CString texteConsole;
	CString pathToGenome;
	int idPatient;
	int idMaladie;
	int medecinConnected = -1;
	int entrepriseConnected = -1;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
