
// ObosDoc.h : интерфейс класса CObosDoc
//


#pragma once
#include "ObosSet.h"


class CObosDoc : public CDocument
{
protected: // создать только из сериализации
	CObosDoc();
	DECLARE_DYNCREATE(CObosDoc)

// Атрибуты
public:
	CObosSet m_ObosSet;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CObosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
