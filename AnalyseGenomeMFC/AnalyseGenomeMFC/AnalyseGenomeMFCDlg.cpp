
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
#include <fstream>
#include <iostream>

using namespace std;

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
}


void CAnalyseGenomeMFCDlg::OnEnChangeEdit1()
{
}

void CAnalyseGenomeMFCDlg::OnBnClickedButton1()
{
	ServiceClient servicesM;

	int t = UpdateData(true);
	if (!t)
	{
		AfxMessageBox(_T("Erreur"));
	}

	CT2CA pszConvertedAnsiString(commande);
	string requete(pszConvertedAnsiString);
	string nomCommande = requete.substr(0, requete.find(":"));
	string arguments = requete.substr(requete.find(":")+1, requete.size()-nomCommande.size());

	if (nomCommande.compare("connexionMedecin") == 0)
	{
		CString message (">> Connexion...\r\n");
		texteConsole.Insert(texteConsole.GetLength(), message);
		int id = stoi(requete.substr(requete.find(":")+1));
		int connexion = servicesM.ConnexionMedecin(id);
		if (connexion == 0)
		{
			CString messageC(">> Connexion effectuée !\r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageC);
			UpdateData(false);
			medecinConnected = stoi(arguments);
		}
		else 
		{
			CString messageNC(">> Connexion échouée. Essayez encore !\r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageNC);
			UpdateData(false);
		}
	}
	else if (nomCommande.compare("connexionEntreprise") == 0)
	{
		if (socketLaunched)
		{
			servicesM.ConnexionEntreprise(arguments, *socket);
			UpdateData(false);
		}
	}

	if (medecinConnected != -1)
	{
		if(nomCommande.compare("deconnexionMedecin") == 0) {
			bool deconnexion = servicesM.DeconnexionMedecin();
			if (deconnexion)
			{
				CString messageD(">> Déconnexion effectuée !\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageD);
				UpdateData(false);
				medecinConnected = -1;
			}
			else
			{
				CString messageND(">> La déconnexion a échouée !\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageND);
				UpdateData(false);
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
				CString messageE(">> Problème lors de la création d'un patient au niveau des arguments fournis\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageE);
				UpdateData(false);
			
				return;
			}

			Patient nouveauPatient = Patient(infos[0], infos[1],infos[2],infos[3]);
			int creaD = servicesM.CreerDossierPatient(nouveauPatient);
			if (creaD == 0)
			{
				CString messageDP(">> Dossier patient créé avec succès !\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageDP);
				UpdateData(false);
			}
			else
			{
				CString messageDPE(">> Erreur lors de la création du patient !\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageDPE);
				UpdateData(false);
			}
		}
		else if (nomCommande.compare("consulterDossier") == 0) {
			int idPatient = stoi(requete.substr(requete.find(":") + 1));
			Patient patientTraite = servicesM.ConsulterDossierPatient(idPatient);
			if (patientTraite.get_nom().size()==0)
			{
				CString messageCDP(">> Ce patient n'existe pas\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageCDP);
			} 
			else
			{
				CString messageCDP(">> Voici le dossier de ce patient :\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageCDP);
				UpdateData(false);
				CString messageCDPD(patientTraite.toString().c_str());
				texteConsole.Insert(texteConsole.GetLength(), messageCDPD);
			}
			
			UpdateData(false);
		}
		else if (nomCommande.compare("parcourirDictionnaires") == 0) {
			vector<Serveur> dicos = servicesM.ConsulterDictionnaires();
			string affichageServeurs;
			CString messageS1(">> Liste des serveurs :\r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageS1);
			UpdateData(false);
			for (vector<Serveur>::iterator i = dicos.begin(); i != dicos.end(); ++i)
			{
				affichageServeurs.append((*i).toString());
				affichageServeurs.append("\r\n");
			}

			CString messageS(affichageServeurs.c_str());
			texteConsole.Insert(texteConsole.GetLength(), messageS);
			texteConsole.Insert(texteConsole.GetLength(), (CString) "\r\n");
			UpdateData(false);
		}
		else if (nomCommande.compare("consulterAnalysesPatient") == 0) {
			int idPatient = stoi(requete.substr(requete.find(":") + 1));
			vector<Analyse> analyses = servicesM.ConsulterAnalysesPatient(idPatient);
			if (analyses.size() == 0)
			{
				CString messageA1(">> Aucune analyse pour ce patient.\r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageA1);
			}
			else
			{
				string affichageAnalyses;
				CString messageA1(">> Liste des analyses du patient : \r\n");
				texteConsole.Insert(texteConsole.GetLength(), messageA1);
				UpdateData(false);

				for (vector<Analyse>::iterator i = analyses.begin(); i != analyses.end(); ++i)
				{
					affichageAnalyses.append((*i).toString());
					affichageAnalyses.append("\r\n");
				}

				CString messageA(affichageAnalyses.c_str());
				texteConsole.Insert(texteConsole.GetLength(), messageA);
				texteConsole.Insert(texteConsole.GetLength(), (CString) "\r\n");
			}
			UpdateData(false);

		}
		else if (nomCommande.compare("consulterResultatAnalyse") == 0) {
			int idAnalyse = stoi(requete.substr(requete.find(":") + 1));
			Analyse analyse = servicesM.ConsulterResultatsAnalyse(idAnalyse);
			CString messageR1(">> Voici le résultat de cette analyse :\r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageR1);
			UpdateData(false);
			int resultat = analyse.get_resultat();
			if (resultat == 1)
			{
				CString messageR(">> Risque d'atteinte de la maladie");
				texteConsole.Insert(texteConsole.GetLength(), messageR);
			}
			else if(resultat==0)
			{
				CString messageR(">> Absence de risque d'atteinte de la maladie");
				texteConsole.Insert(texteConsole.GetLength(), messageR);
			}
			else
			{
				CString messageR(">> Aucune analyse avec cet ID.");
				texteConsole.Insert(texteConsole.GetLength(), messageR);
			}
		
			texteConsole.Insert(texteConsole.GetLength(), (CString)"\r\n");
			UpdateData(false);
		}
		else if (nomCommande.compare("effectuerAnalyse") == 0) 
		{
			string args = requete.substr(requete.find(":") + 1);

			vector<string> infos;
			stringstream ss(args); // Turn the string into a stream.
			string elem;

			while (getline(ss, elem, ',')) {
				infos.push_back(elem);
			}
			string maladie = infos[0];
			int idPatient = stoi(infos[2]);
			int idMaladie = stoi(infos[3]);
			string pathToGenome = infos[1];
			//-------------------------------------------------------------------------------
			servicesM.recupererMots(*socket, maladie);
			/*ifstream dico("dicoMalade.txt");
			string retSock;
			dico>>retSock;
			CString pathGenome("genomeMalade.txt");
			int idPatient2 = 10;
			int idMaladie2 = 1;
			servicesM.EffectuerAnalyse(retSock, pathGenome, idPatient2, idMaladie2);*/
		}
	}
	if (entrepriseConnected != -1)
	{
		if (nomCommande.compare("deconnexionEntreprise") == 0) { //A voir !
			servicesM.DeconnexionEntreprise(*socket);
			CString messageNC(">> Déconnexion...\r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageNC);
		}
		else if (nomCommande.compare("modifierDescriptionDictionaire") == 0)
		{
			servicesM.ModifierDescriptionDictionnaire(arguments, *socket);
		}
		else if (nomCommande.compare("ajouterMaladie") == 0)
		{
			string args = requete.substr(requete.find(":") + 1);

			vector<string> infos;
			stringstream ss(args); // Turn the string into a stream.
			string elem;

			while (getline(ss, elem, ',')) {
				infos.push_back(elem);
			}
			servicesM.AjouterMaladie(infos[0], infos[1], *socket);
		}
		else if (nomCommande.compare("consulterDictionnaire") == 0)
		{
			CString messageServ(">> Noms des maladies du serveur : \r\n");
			texteConsole.Insert(texteConsole.GetLength(), messageServ);
			servicesM.ConsulterDictionnaire(*socket);
		}
		else if (nomCommande.compare("consulterMetaDonnees") == 0)
		{
			servicesM.consulterMetaDonnees(*socket);
		}
		else if (nomCommande.compare("supprimerMaladie") == 0)
		{
			servicesM.SupprimerMaladie(arguments, *socket);
		}
		else if (nomCommande.compare("modifierMaladie")==0)
		{
			string args = requete.substr(requete.find(":") + 1);

			vector<string> infos;
			stringstream ss(args); // Turn the string into a stream.
			string elem;

			while (getline(ss, elem, ',')) {
				infos.push_back(elem);
			}
			servicesM.ModifierMaladie(infos[0], infos[1], *socket);
		}
	}	
}

void CAnalyseGenomeMFCDlg::OnStnClickedStaticAffichage()
{
}


void CAnalyseGenomeMFCDlg::OnBnClickedButton3()
{
	CString ip("localhost");
	socket = new ConnectedSocket();
	socket->setOwner(this);
	socket->Create();
	socket->Connect(ip, 8080);
	socketLaunched = true;
}


void CAnalyseGenomeMFCDlg::OnBnClickedButton4()
{
	socket->Close();
	AfxMessageBox(_T("Connection with the server closed."));
	socketLaunched = false;
	//socket.Send("connexion:0:", strlen("connexion:0:"));
}
