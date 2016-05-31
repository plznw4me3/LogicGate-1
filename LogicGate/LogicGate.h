
// LogicGate.h : main header file for the LogicGate application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif
//
#include "resource.h"       // main symbols


// CLogicGateApp:
//
// See LogicGate.cpp for the implementation of this class
//
//

class CLogicGateApp : public CWinApp
{
public:
	CLogicGateApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLogicGateApp theApp;
