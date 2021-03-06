
// LogicGateDoc.cpp : implementation of the CLogicGateDoc class
//

#include "stdafx.h"
#include "Gate.h"
#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "NOT.h"
#include "XOR.h"
#include "DPP.h"
#include "TPP.h"
#include "JKPP.h"
#include "Wire.h"
#include "Clock.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LogicGate.h"
#endif

#include "LogicGateDoc.h"
#include "LogicGateView.h"
#include "LogicGate.h"
#include "MainFrm.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLogicGateDoc

IMPLEMENT_DYNCREATE(CLogicGateDoc, CDocument)

BEGIN_MESSAGE_MAP(CLogicGateDoc, CDocument)
END_MESSAGE_MAP()

// CLogicGateDoc construction/destruction

CLogicGateDoc::CLogicGateDoc()
{
	cnt = 0;
	logic_size = 0;
	// TODO: add one-time construction code here
}

CLogicGateDoc::~CLogicGateDoc()
{
}

BOOL CLogicGateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	id.RemoveAll();
	pos.RemoveAll();
	rotate.RemoveAll();
	cnt = 100;
	logic_size = 0;
	
	// View에 있던 정보 초기화
	POSITION ppos = GetFirstViewPosition();
	CLogicGateView *pView = (CLogicGateView *)GetNextView(ppos);
	pView->and.logic.RemoveAll();
	pView->nand.logic.RemoveAll();
	pView->or.logic.RemoveAll();
	pView->not.logic.RemoveAll();
	//pView->nor.logic.RemoveAll();
	//pView->xor.logic.RemoveAll();
	pView->dpp.logic.RemoveAll();
	pView->tpp.logic.RemoveAll();
	pView->jkpp.logic.RemoveAll();
	pView->sw_flag = false;
	pView->makeLogic = false;

	//CLogicGateView *pView = (CLogicGateView *)((CMainFrame *)(AfxGetApp()->m_pMainWnd))->GetActiveView();
	return TRUE;
}




// CLogicGateDoc serialization

void CLogicGateDoc::Serialize(CArchive& ar)
{
	POSITION ppos = GetFirstViewPosition();
	CLogicGateView *pView = (CLogicGateView *)GetNextView(ppos);
	
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		for (int i = 0; i < id.GetSize(); i++) {
			CString str;
			str.Format(_T("%d %d %d %d "), id[i], pos[i].x, pos[i].y, rotate[i]);
			ar << id[i] << pos[i].x << pos[i].y << rotate[i];
			//ar << str;
		}
		//id.Serialize(ar);
		//pos.Serialize(ar);
		//r.Serialize(ar);

	}
	else
	{
		// TODO: add loading code here
		int d, x, y, r;
		CString str;
		//while (1) {
		ar >> str;
			
		//}
	}
	logic_size++;
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLogicGateDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLogicGateDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLogicGateDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLogicGateDoc diagnostics

#ifdef _DEBUG
void CLogicGateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLogicGateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLogicGateDoc commands