#pragma once


// ���������� ���� AddDlg

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~AddDlg();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

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
