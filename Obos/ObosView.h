
// ObosView.h : интерфейс класса CObosView
//

#pragma once
#include "afxwin.h"

class CObosSet;

class CObosView : public CRecordView
{
protected: // создать только из сериализации
	CObosView();
	DECLARE_DYNCREATE(CObosView)

public:
	enum{ IDD = IDD_OBOS_FORM };
	CObosSet* m_pSet;

// Атрибуты
public:
	CObosDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CObosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
//	CString m_Id;
	CString m2;
	CString m3;
	CString m4;
	CString m5;
	CString m6;
	afx_msg void OnBnClickedButton1();
	CString m_Filter;
	CString m_Filter_Val;
//	CComboBox m_FL;
	CEdit m_FL;
	afx_msg void OnRecordAddrecord();
	afx_msg void OnRecordDeleterecord();
//	int Id;
	afx_msg void OnRecordEditrecord();
	afx_msg void OnRecordSql();
	afx_msg void OnMove();
};

#ifndef _DEBUG  // отладочная версия в ObosView.cpp
inline CObosDoc* CObosView::GetDocument() const
   { return reinterpret_cast<CObosDoc*>(m_pDocument); }
#endif

