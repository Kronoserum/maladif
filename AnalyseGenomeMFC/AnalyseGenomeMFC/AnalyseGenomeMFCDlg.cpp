
// AnalyseGenomeMFCDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenomeMFC.h"
#include "AnalyseGenomeMFCDlg.h"
#include "afxdialogex.h"
#include "Patient.h"
#include "Database.h"
#include "PatientDADatabase.h"
#include "ServiceClient.h"
#include <vector>
#include <sstream>
#include "ServeurDADatabase.h"
#include "EntrepriseDADatabase.h"
#include "MedecinDADatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
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


// boîte de dialogue CAnalyseGenomeMFCDlg



CAnalyseGenomeMFCDlg::CAnalyseGenomeMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ANALYSEGENOMEMFC_DIALOG, pParent)
	, commande(_T(""))
	, texteConsole(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnalyseGenomeMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, commande);
	DDX_Text(pDX, IDC_EDIT2, texteConsole);
}

BEGIN_MESSAGE_MAP(CAnalyseGenomeMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_StartServer, &CAnalyseGenomeMFCDlg::OnBnClickedStartserver)
	ON_BN_CLICKED(IDC_ShutDownServer, &CAnalyseGenomeMFCDlg::OnBnClickedShutdownserver)
	ON_BN_CLICKED(IDC_Database, &CAnalyseGenomeMFCDlg::OnBnClickedDatabase)
	ON_BN_CLICKED(IDC_BUTTON1, &CAnalyseGenomeMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAnalyseGenomeMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAnalyseGenomeMFCDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// gestionnaires de messages pour CAnalyseGenomeMFCDlg

BOOL CAnalyseGenomeMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
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

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
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

void CAnalyseGenomeMFCDlg::OnOK(void)
{
	CWnd* pWnd = GetFocus();
	if (GetDlgItem(IDOK) == pWnd)
	{
		CDialog::OnOK();
		return;
	}

	// Enter key was hit -> do whatever you want
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CAnalyseGenomeMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CAnalyseGenomeMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAnalyseGenomeMFCDlg::OnBnClickedStartserver()
{
	
}


void CAnalyseGenomeMFCDlg::OnBnClickedShutdownserver()
{
	
}





void CAnalyseGenomeMFCDlg::OnBnClickedDatabase()
{
	//Database test

	Patient patient;
	string patient_str;
	int patient_id = 8;

	ServiceClient smc;
	
	

	//database.create_tables();

	//ServeurDADatabase serveur_DA_database;
	//Serveur s("ok", "ok",1);

	//serveur_DA_database.write_serveur(s);

	//EntrepriseDADatabase entreprise_DA_database;
	//Entreprise e("ok", "ok");

	//entreprise_DA_database.write_entreprise(e);

	//Patient p;
	//p.set_nom("lol");

	//patient_DA_database.write_patient(p);

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


void CAnalyseGenomeMFCDlg::OnEnChangeEdit1()
{
}

void CAnalyseGenomeMFCDlg::OnBnClickedButton1()
{
	CWnd *label = GetDlgItem(IDC_STATIC_AFFICHAGE);
	ServiceClient servicesM;

	int t = UpdateData(true);
	if (!t)
	{
		AfxMessageBox(_T("Erreur"));
	}

	CT2CA pszConvertedAnsiString(commande);
	string requete(pszConvertedAnsiString);
	string nomCommande = requete.substr(0, requete.find(":"));
	if (nomCommande.compare("connexionMedecin") == 0)
	{
		CString message ("Connexion effectuée ! (à supprimer quand service ok)\r\n");
		texteConsole.Insert(texteConsole.GetLength(), message);
		label->SetWindowText(_T("Connexion effectuée ! (à supprimer quand service ok)"));
		int id = stoi(requete.substr(requete.find(":")+1));
		bool connexion = servicesM.ConnexionMedecin(id);
		if (connexion)
		{
			
			label->SetWindowText(_T("Connexion effectuée !"));
		}
		else 
		{
			label->SetWindowText(_T("Connexion échouée. Essayez encore !"));
		}
		UpdateData(false);
	}
	else if(nomCommande.compare("deconnexionMedecin") == 0) {
		bool deconnexion = servicesM.DeconnexionMedecin();
		if (deconnexion)
		{
			label->SetWindowText(_T("Déconnexion effectuée !"));
		}
		else
		{
			label->SetWindowText(_T("La déconnexion a échouée !"));
		}
	}
	else if (nomCommande.compare("creerDossier") == 0) {
		string infosPatient = requete.substr(requete.find(":") + 1);
		
		vector<string> infos;
		stringstream ss(infosPatient); // Turn the string into a stream.
		string elem;

		while (getline(ss, elem, ',')) {
			infos.push_back(elem);
		}

		if (infos.size() != 4)
		{
			label->SetWindowText(_T("Problème lors de la création d'un patient au niveau des arguments fournis"));
			return;
		}

		Patient nouveauPatient = Patient(infos[0], infos[1],infos[2],infos[3]);
		int creaD = servicesM.CreerDossierPatient(nouveauPatient);
		if (creaD == 1)
		{
			label->SetWindowText(_T("Dossier patient créé avec succès !"));
		}
		else
		{
			label->SetWindowText(_T("Erreur lors de la création du patient !"));
		}
	}
	else if (nomCommande.compare("supprimerDossier") == 0) {
		int idPatient = stoi(requete.substr(requete.find(":") + 1));
	}
	else if (nomCommande.compare("consulterDossier") == 0) {
		int idPatient = stoi(requete.substr(requete.find(":") + 1));
	}
	else if (nomCommande.compare("consulterAnalysesPatient") == 0) {
		int idPatient = stoi(requete.substr(requete.find(":") + 1));
		vector<Analyse> analyses = servicesM.ConsulterAnalysesPatient(idPatient);
		string affichageAnalyses;
		for (vector<Analyse>::iterator i = analyses.begin(); i != analyses.end(); ++i) 
		{ 
			affichageAnalyses.append((*i).toString());
			affichageAnalyses.append("\r\n");
		}
		affichageAnalyses = "test";
		label->SetWindowText(LPCTSTR(affichageAnalyses.c_str()));

	}
	else if (nomCommande.compare("consulterResultatAnalyse") == 0) {
		int idAnalyse = stoi(requete.substr(requete.find(":") + 1));
		//servicesM.ConsulterResultatsAnalyse(idAnalyse);
	}
	else if (nomCommande.compare("effectuerAnalyse") == 0) {
		//A voir s'il faut découper la réalisation (cf exigences fonctionnelles)
	}
	else
	{
		AfxMessageBox(_T("Requête incorrecte !"));
	}
	
	
}

void CAnalyseGenomeMFCDlg::OnStnClickedStaticAffichage()
{
}


void CAnalyseGenomeMFCDlg::OnBnClickedButton3()
{
	CString ip("localhost");
	socket.Create();
	socket.Connect(ip, 8080);
}


void CAnalyseGenomeMFCDlg::OnBnClickedButton4()
{
	//socket.Close();
	socket.Send("connexion:0:", strlen("connexion:0:"));
}
