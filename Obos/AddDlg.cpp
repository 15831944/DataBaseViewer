// AddDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Obos.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// диалоговое окно AddDlg

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddDlg::IDD, pParent)
	, m_Id(0)
	, m_Name(_T(""))
	, m_City(_T(""))
	, m_Pred(_T(""))
	, m_Country(_T(""))
	, m_Pay(_T(""))
	, m_Int(0)
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Id);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_City);
	DDX_Text(pDX, IDC_EDIT4, m_Pred);
	DDX_Text(pDX, IDC_EDIT5, m_Country);
	DDX_Text(pDX, IDC_EDIT6, m_Pay);
	DDX_Text(pDX, IDC_EDIT7, m_Int);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений AddDlg
