
// ObosSet.cpp : ���������� ������ CObosSet
//

#include "stdafx.h"
#include "Obos.h"
#include "ObosSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CObosSet

// ����������� ��� 11 ��� 2018 �., 12:59

IMPLEMENT_DYNAMIC(CObosSet, CRecordset)

CObosSet::CObosSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// ��������� ������ ����������� ����� ��������� ��������������� ������ ��� 
// ������ ���������������� ����������. ������� #error ����� ��������� ������ ����������� 
// � ����� ������������. ��������, 
// ����������� ��������� ������ � ������ ���� ��� ������������ ������ �������� �����������.
CString CObosSet::GetDefaultConnect()
{
	return _T("DSN=BucketOfStuff;DBQ=db1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CObosSet::GetDefaultSQL()
{
	return _T("[����������]");
}

void CObosSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// ����� �������, ��� RFX_Text() � RFX_Int(), ������� �� ���� 
// ���������� �����, � �� �� ���� ���� � ���� ������.
// ODBC ��������� ������� ������������� ������������� �������� ������� � ������� ����
	RFX_Long(pFX, _T("[�������������]"), column1);
	RFX_Text(pFX, _T("[��������]"), column2);
	RFX_Text(pFX, _T("[�����]"), column3);
	RFX_Text(pFX, _T("[�������������]"), column4);
	RFX_Text(pFX, _T("[������]"), column5);
	RFX_Text(pFX, _T("[�������������]"), column6);
}
/////////////////////////////////////////////////////////////////////////////
// CObosSet �����������

#ifdef _DEBUG
void CObosSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CObosSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

