
// Med'IF_Serveur.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMedIF_ServeurApp�:
// Consultez Med'IF_Serveur.cpp pour l'impl�mentation de cette classe
//

class CMedIF_ServeurApp : public CWinApp
{
public:
	CMedIF_ServeurApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CMedIF_ServeurApp theApp;