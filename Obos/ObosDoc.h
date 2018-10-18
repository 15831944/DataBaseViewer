
// ObosDoc.h : ��������� ������ CObosDoc
//


#pragma once
#include "ObosSet.h"


class CObosDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CObosDoc();
	DECLARE_DYNCREATE(CObosDoc)

// ��������
public:
	CObosSet m_ObosSet;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CObosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
