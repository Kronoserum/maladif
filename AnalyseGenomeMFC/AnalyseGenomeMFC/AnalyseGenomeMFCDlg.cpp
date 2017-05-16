
// AnalyseGenomeMFCDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "AnalyseGenomeMFC.h"
#include "AnalyseGenomeMFCDlg.h"
#include "afxdialogex.h"
#include "Patient.h"
#include "Database.h"
#include "PatientDADatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// bo�te de dialogue CAnalyseGenomeMFCDlg



CAnalyseGenomeMFCDlg::CAnalyseGenomeMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ANALYSEGENOMEMFC_DIALOG, pParent)
	, commande(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnalyseGenomeMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, commande);
}

BEGIN_MESSAGE_MAP(CAnalyseGenomeMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_StartServer, &CAnalyseGenomeMFCDlg::OnBnClickedStartserver)
	ON_BN_CLICKED(IDC_ShutDownServer, &CAnalyseGenomeMFCDlg::OnBnClickedShutdownserver)
	ON_BN_CLICKED(IDC_Database, &CAnalyseGenomeMFCDlg::OnBnClickedDatabase)
	ON_BN_CLICKED(IDC_BUTTON1, &CAnalyseGenomeMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// gestionnaires de messages pour CAnalyseGenomeMFCDlg

BOOL CAnalyseGenomeMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// TODO: ajoutez ici une initialisation suppl�mentaire

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CAnalyseGenomeMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CAnalyseGenomeMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CAnalyseGenomeMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAnalyseGenomeMFCDlg::OnBnClickedStartserver()
{
	listenerSock.Create(LISTENER_PORT);

	if (listenerSock.Listen())
		AfxMessageBox(_T("Now listening"));
	else
	{
		AfxMessageBox(_T("Unable to listen"));
		listenerSock.Close();
	}
}


void CAnalyseGenomeMFCDlg::OnBnClickedShutdownserver()
{
	listenerSock.ShutDown(2);
}





void CAnalyseGenomeMFCDlg::OnBnClickedDatabase()
{
	//Database test

	Patient patient;
	string patient_str;
	int patient_id = 8;

	Database database;
	database.open_database();

	//database.create_tables();

	PatientDADatabase patient_DA_database;
	patient_DA_database.set_database(database.get_database());

	Patient p;
	p.set_nom("lol");

	patient_DA_database.write_patient(p);

	/*if (patient_DA_database.read_patient(patient, patient_id) == 0)
	{
		patient_str = to_string(patient.get_id()) + ", " +
			patient.get_nom() + ", " +
			patient.get_prenom() + ", " +
			patient.get_mail() + ", " +
			patient.get_mdp();

		AfxMessageBox(CString(patient_str.c_str()));
	}*/
}


void CAnalyseGenomeMFCDlg::OnBnClickedButton1()
{
	int t = UpdateData(true);
	if (!t)
	{
		AfxMessageBox(_T("Erreur"));
	}

	AfxMessageBox(_T("Commande envoy�e ! (� coder) " + commande ));
	CWnd *label = GetDlgItem(IDC_STATIC_AFFICHAGE);
	label->SetWindowText(commande);
}

