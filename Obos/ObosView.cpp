
// ObosView.cpp : ���������� ������ CObosView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Obos.h"
#endif
#include "AddDlg.h"
#include "ObosSet.h"
#include "ObosDoc.h"
#include "ObosView.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CObosView

IMPLEMENT_DYNCREATE(CObosView, CRecordView)

BEGIN_MESSAGE_MAP(CObosView, CRecordView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CObosView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_CHANGE(IDC_EDIT4, &CObosView::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CObosView::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_ADDRECORD, &CObosView::OnRecordAddrecord)
	ON_COMMAND(ID_RECORD_DELETERECORD, &CObosView::OnRecordDeleterecord)
	ON_COMMAND(ID_RECORD_EDITRECORD, &CObosView::OnRecordEditrecord)
	ON_COMMAND(ID_RECORD_SQL, &CObosView::OnRecordSql)
	ON_COMMAND(ID_MOVE, &CObosView::OnMove)
END_MESSAGE_MAP()

// ��������/����������� CObosView

CObosView::CObosView()
	: CRecordView(CObosView::IDD)
	
	, m_Filter(_T(""))
	, m_Filter_Val(_T(""))
	
{
	m_pSet = NULL;
	// TODO: �������� ��� ��������

}

CObosView::~CObosView()
{
}

void CObosView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// ����� ��� ������� ������� DDX_Field* ��� ����������� ��������� ���������� � ����� ���� ������, ��������
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// ��� ��������� �������������� �������� ��. ������� MSDN � ODBC
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);

	/*
	DDX_Text(pDX, IDC_EDIT2, m2);
	DDX_Text(pDX, IDC_EDIT3, m3);
	DDX_Text(pDX, IDC_EDIT4, m4);
	DDX_Text(pDX, IDC_EDIT5, m5);
	DDX_Text(pDX, IDC_EDIT6, m6);*/
	DDX_Text(pDX, IDC_EDIT7, m_Filter);
	DDX_CBString(pDX, IDC_COMBO1, m_Filter_Val);
	//  DDX_Control(pDX, IDC_COMBO1, m_FL);
	DDX_Control(pDX, IDC_EDIT7, m_FL);

}

BOOL CObosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CObosView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ObosSet;
	CRecordView::OnInitialUpdate();

}


// ������ CObosView


void CObosView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CObosView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CObosView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CObosView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void CObosView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CObosView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CObosView

#ifdef _DEBUG
void CObosView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CObosView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CObosDoc* CObosView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CObosDoc)));
	return (CObosDoc*)m_pDocument;
}
#endif //_DEBUG


// ��������� ���� ������ CObosView
CRecordset* CObosView::OnGetRecordset()
{
	return m_pSet;
}



// ����������� ��������� CObosView


void CObosView::OnEnChangeEdit4()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CRecordView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  �������� ��� �������� ����������
}


void CObosView::OnBnClickedButton1()
{
	UpdateData(TRUE);
	
	CString filter;
	m_FL.GetWindowText(filter);
	
	if(filter==L""){
	m_pSet->m_strFilter="";
	}
	else{
		UpdateData(TRUE);
		filter=m_Filter_Val + " Like '" + filter + "'";

		m_pSet->m_strFilter=filter;
	}
	m_pSet->Requery();
	
	UpdateData(FALSE);
	// TODO: �������� ���� ��� ����������� �����������
}


void CObosView::OnRecordAddrecord()
{
	AddDlg dlg;
	if(dlg.DoModal()==IDOK){
		if(dlg.m_Id==0){
			MessageBox("Cannot add without id");
			return;
		}
		if(dlg.m_Name.IsEmpty()){
			MessageBox("Cannot add without company name");
			return;
		}
		m_pSet->AddNew();
		m_pSet->column1=dlg.m_Id;
		m_pSet->column2=dlg.m_Name;
		m_pSet->column3=dlg.m_City;
		m_pSet->column4=dlg.m_Pred;
		m_pSet->column5=dlg.m_Country;
		m_pSet->column6==dlg.m_Pay;

		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(FALSE);
	}
}

void CObosView::OnRecordDeleterecord()
{
	try{
		m_pSet->Delete();
	}
	catch(CDBException* error){
		AfxMessageBox(error->m_strError);
		error->Delete();
		m_pSet->MoveFirst();
		UpdateData(FALSE);
		return;
	}
	m_pSet->MoveLast();
	UpdateData(FALSE);
	// TODO: �������� ���� ��� ����������� ������
}


void CObosView::OnRecordEditrecord()
{AddDlg dlg;
	if(dlg.DoModal()==IDOK){
		if(dlg.m_Id==0){
			MessageBox("Cannot add without id");
			return;
		}
		if(dlg.m_Name.IsEmpty()){
			MessageBox("Cannot add without company name");
			return;
		}
		m_pSet->Edit();
		m_pSet->column1=dlg.m_Id;
		m_pSet->column2=dlg.m_Name;
		m_pSet->column3=dlg.m_City;
		m_pSet->column4=dlg.m_Pred;
		m_pSet->column5=dlg.m_Country;
		m_pSet->column6==dlg.m_Pay;

		m_pSet->Update();
		
		//std::string str="Get="+std::to_string(m_pSet->GetRecordCount());	

		UpdateData(FALSE);

	// TODO: �������� ���� ��� ����������� ������
}
}

void CObosView::OnRecordSql()
{
	/*
	CDatabase db;
	db.OpenEx(_T("DSN=BucketOfStuff;UID=admin"));
	//db.ExecuteSQL( _T("UPDATE ���������� SET ����� = 'Lviv' WHERE (����� = '�����') "));
	std::string str1 ="INSERT INTO ����������2 (�������������,��������) values('"+std::to_string(12)+"', 'TestUser') ";
	LPCTSTR str2;
	str2=str1.c_str();
	db.ExecuteSQL( _T(str2));
	db.Close();
	 UPDATE titles  
SET price = price * 1.1  
WHERE (pub_id = '0766') 
	
	m_pSet->MoveFirst();
		int i=0;
		while(!m_pSet->IsEOF()){
			i++;
			MessageBox(m_pSet->column2);
			m_pSet->MoveNext();
		}
			MessageBox(std::to_string(i).c_str());
		
			m_pSet->Move(0); */
}


void CObosView::OnMove()
{


	// TODO: �������� ���� ��� ����������� ������
}
