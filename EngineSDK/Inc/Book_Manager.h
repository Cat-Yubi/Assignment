#pragma once

#include "Base.h"

BEGIN(Engine)

class CBook_Manager final : public CBase
{
private:
	CBook_Manager();
	virtual ~CBook_Manager() = default;

public:
	HRESULT Initialize();

	void DisplayBook(string strAuthor, string strTitle);
	void DisplayBorrowBook(string strAuthor, string strTitle);

	class CBook* BorrowBook(string strTitle);
public:
	HRESULT				Add_Book(string strAuthor, string strTitle, _int iCount);

	list<class CBook*>* Find_BookList(string strAuthor);
	class CBook*				Find_Book(list<class CBook*>* pBookList, string strTitle);

private:
	unordered_map<string, list<class CBook*>>		m_Library;
	unordered_map<string, pair<_int, _int>>			m_LibraryByCount;
	
public:
	static CBook_Manager* Create();
	virtual void Free() override;
};

END