
// ObosSet.h: ��������� ������ CObosSet
//


#pragma once

// ����������� ��� 11 ��� 2018 �., 12:59

class CObosSet : public CRecordset
{
public:
	CObosSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CObosSet)

// ������ ����� � ����������

// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
// ������������ �������� ��������������. ��� ������� ����� �������� ��� ����� �� 
// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
// ��� ��������� ��� �������, ��� � ���� ��������������).

	long	column1;
	CString	column2;
	CString	column3;
	CString	column4;
	CString	column5;
	CString	column6;

// ���������������
	// ������ ������ ��������������� ����������� �������
	public:
	virtual CString GetDefaultConnect();	// ������ ����������� �� ���������

	virtual CString GetDefaultSQL(); 	// ��� SQL �� ��������� ���  ������ �������
	virtual void DoFieldExchange(CFieldExchange* pFX);	// ��������� RFX

// ����������
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

