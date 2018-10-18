
// ObosSet.h: интерфейс класса CObosSet
//


#pragma once

// создаваемый код 11 мая 2018 г., 12:59

class CObosSet : public CRecordset
{
public:
	CObosSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CObosSet)

// Данные полей и параметров

// Следующие типы строк (если присутствуют) отражают фактические типы данных 
// поля базы данных - CStringA для типов данных ANSI и CStringW для типов 
// данных Юникода. Это должно предотвратить выполнение драйвером ODBC 
// потенциально ненужных преобразований. При желании можно заменить эти члены на 
// типы CString, и драйвер ODBC выполнит все необходимые преобразования.
// (Примечание. Необходимо использовать драйвер ODBC версии 3.5 или более поздней 
// для поддержки как Юникода, так и этих преобразований).

	long	column1;
	CString	column2;
	CString	column3;
	CString	column4;
	CString	column5;
	CString	column6;

// Переопределение
	// Мастер создал переопределения виртуальных функций
	public:
	virtual CString GetDefaultConnect();	// Строка подключения по умолчанию

	virtual CString GetDefaultSQL(); 	// код SQL по умолчанию для  набора записей
	virtual void DoFieldExchange(CFieldExchange* pFX);	// поддержка RFX

// Реализация
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

