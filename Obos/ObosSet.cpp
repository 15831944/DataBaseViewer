
// ObosSet.cpp : реализация класса CObosSet
//

#include "stdafx.h"
#include "Obos.h"
#include "ObosSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CObosSet

// создаваемый код 11 мая 2018 г., 12:59

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

// Следующая строка подключения может содержать незашифрованные пароли или 
// другую конфиденциальную информацию. Удалите #error после просмотра строки подключения 
// в целях безопасности. Возможно, 
// потребуется сохранить пароль в другом виде или использовать другую проверку подлинности.
CString CObosSet::GetDefaultConnect()
{
	return _T("DSN=BucketOfStuff;DBQ=db1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CObosSet::GetDefaultSQL()
{
	return _T("[Поставщики]");
}

void CObosSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Такие макросы, как RFX_Text() и RFX_Int(), зависят от типа 
// переменной члена, а не от типа поля в базе данных.
// ODBC выполняет попытку автоматически преобразовать значение столбца к нужному типу
	RFX_Long(pFX, _T("[КодПоставщика]"), column1);
	RFX_Text(pFX, _T("[Название]"), column2);
	RFX_Text(pFX, _T("[Город]"), column3);
	RFX_Text(pFX, _T("[Представитель]"), column4);
	RFX_Text(pFX, _T("[Страна]"), column5);
	RFX_Text(pFX, _T("[УсловияОплаты]"), column6);
}
/////////////////////////////////////////////////////////////////////////////
// CObosSet диагностика

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

