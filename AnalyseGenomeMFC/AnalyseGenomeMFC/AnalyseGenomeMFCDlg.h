
// AnalyseGenomeMFCDlg.h : fichier d'en-tête
//

#pragma once

#include "ListenerSocket.h"

// boîte de dialogue CAnalyseGenomeMFCDlg
class CAnalyseGenomeMFCDlg : public CDialogEx
{
// Construction
public:
	CAnalyseGenomeMFCDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYSEGENOMEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartserver();
	afx_msg void OnBnClickedShutdownserver();
	afx_msg void OnBnClickedService();
	afx_msg void OnBnClickedDatabase();

private:
	const int LISTENER_PORT = 8080;
	ListenerSocket listenerSock;
};
