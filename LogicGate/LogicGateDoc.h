
// LogicGateDoc.h : interface of the CLogicGateDoc class
//


#pragma once


class CLogicGateDoc : public CDocument
{
protected: // create from serialization only
	CLogicGateDoc();
	DECLARE_DYNCREATE(CLogicGateDoc)


// Attributes
public:
	CArray<INT, INT&> id;
	CArray<POINT, POINT&> pos;
	CArray<INT, INT&> rotate;
	int cnt;
	int logic_size;
// Operations
public:
	
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CLogicGateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
