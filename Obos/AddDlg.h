#pragma once


// диалоговое окно AddDlg

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~AddDlg();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_Id;
	CString m_Name;
	CString m_City;
	CString m_Pred;
	CString m_Country;
	CString m_Pay;
	int m_Int;
};
