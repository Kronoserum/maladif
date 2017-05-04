
// Med'IF_Serveur.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMedIF_ServeurApp :
// Consultez Med'IF_Serveur.cpp pour l'implémentation de cette classe
//

class CMedIF_ServeurApp : public CWinApp
{
public:
	CMedIF_ServeurApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMedIF_ServeurApp theApp;