#include "Book_Manager.h"
#include "Level.h"
#include "Book.h"
CBook_Manager::CBook_Manager()
{

}

HRESULT CBook_Manager::Initialize()
{
	return S_OK;
}

void CBook_Manager::DisplayBook(string strAuthor, string strTitle)
{
	if (strAuthor == "" && strTitle == "")
	{
		for (auto& itAuthor : m_Library)
		{
			cout << "작가 : " << itAuthor.first << endl;
			
			_int iBookCount = 0;
			for (auto& itBook : itAuthor.second)
			{
				auto itCount = m_LibraryByCount.find(itBook->Get_Title());

				if (itCount != m_LibraryByCount.end())
					cout << itBook->Get_Title() << " : " << itCount->second.first << " / " << itCount->second.second << "\t";

				iBookCount++;

				if (iBookCount >= 5) cout << endl; iBookCount = 0;
			}
			cout << endl;
		}
	}
	else if (strTitle == "")
	{
		auto BookList = Find_BookList(strAuthor);

		if (nullptr == BookList)
		{
			cout << "해당 작가의 책이 검색되지 않았습니다." << endl;
			getchar();
			return;
		}

		cout << "작가 : " << strAuthor << endl;

		_int iBookCount = 0;
		for (auto& itBook : *BookList)
		{
			auto itCount = m_LibraryByCount.find(itBook->Get_Title());

			if (itCount != m_LibraryByCount.end())
				cout << itBook->Get_Title() << " : " << itCount->second.first << " / " << itCount->second.second << "\t";

			iBookCount++;
			if (iBookCount >= 5) cout << endl; iBookCount = 0;
		}

		cout << endl;
	}
	else
	{
		auto itBookbyTitle = m_LibraryByCount.find(strTitle);
		if (itBookbyTitle == m_LibraryByCount.end())
		{
			cout << "해당 책이 존재하지 않습니다." << endl;
			getchar();
			return;
		}

		for (auto& itAuthor : m_Library)
		{
			for (auto& itBook : itAuthor.second)
			{
				if (itBook->Get_Title() == strTitle)
				{
					cout << itBook->Get_Title() << " : " << itBookbyTitle->second.first << " / " << itBookbyTitle->second.second << endl;
					getchar();
					return;
				}
			}
		}
	}
}

void CBook_Manager::DisplayBorrowBook(string strAuthor, string strTitle)
{
	if (strAuthor == "" && strTitle == "")
	{
		cout << "현재 대여 중인 책 목록" << endl;
		for (const auto& it : m_LibraryByCount)
		{
			const string& title = it.first;
			const auto& countInfo = it.second;

			if (countInfo.second > countInfo.first)
				cout << title << "\t" << (countInfo.second - countInfo.first) << "권 대여 중" << endl;

		}
		cout << endl;
	}
	else if (strTitle == "")
	{
		auto BookList = Find_BookList(strAuthor);

		if (nullptr == BookList)
		{
			cout << "해당 작가의 책이 검색되지 않았습니다." << endl;
			getchar();
			return;
		}

		cout << strAuthor << "작가의 대여 중인 책 목록" << endl;

		for (const auto& itBook : *BookList)
		{
			const string& title = itBook->Get_Title();
			auto itCount = m_LibraryByCount.find(title);

			if (itCount != m_LibraryByCount.end() && itCount->second.second > itCount->second.first)
				cout << title << "\t" << (itCount->second.second - itCount->second.first) << "권 대여 중" << endl;

		}
		cout << endl;
	}
	else
	{
		auto itBookbyTitle = m_LibraryByCount.find(strTitle);
		if (itBookbyTitle == m_LibraryByCount.end())
		{
			cout << "해당 책이 존재하지 않습니다." << endl;
			getchar();
			return;
		}

		const auto& countInfo = itBookbyTitle->second;
		if (countInfo.first > countInfo.second)
			cout << itBookbyTitle->first << "\t" << (countInfo.second - countInfo.first) << "권 대여 중" << endl;
		else
			cout << "해당 책은 현재 대여 중이 아닙니다." << endl;

		getchar();
	}
}

CBook* CBook_Manager::BorrowBook(string strTitle)
{
	for (auto& itBookList : m_Library)
	{
		for (auto& itBook : itBookList.second)
		{
			if (itBook->Get_Title() == strTitle)
			{
				auto itCount = m_LibraryByCount.find(strTitle);

				if (itCount != m_LibraryByCount.end())
				{
					auto& countInfo = itCount->second;

					if (countInfo.second > 0)
					{
						countInfo.first--;
						cout << "책 제목: " << strTitle << " 대여 완료." << endl;
						return itBook;
					}
					else
					{
						cout << "해당 책은 모두 대여 중입니다." << endl;
						return nullptr;
					}
				}
			}
		}
	}

	cout << "해당 책이 검색되지 않았습니다." << endl;
	return nullptr;
}


HRESULT CBook_Manager::Add_Book(string strAuthor, string strTitle, _int iCount)
{
	list<CBook*>* pBookList = Find_BookList(strAuthor);

	if (nullptr == pBookList)
	{
		list<CBook*> BookList;
		BookList.push_back(CBook::Create(strAuthor, strTitle));

		m_Library.emplace(strAuthor, BookList);
		m_LibraryByCount.emplace(strTitle, make_pair(iCount, iCount));

		return S_OK;
	}

	if (Find_Book(pBookList, strTitle))
	{
		auto iter = m_LibraryByCount.find(strTitle);
		if (iter != m_LibraryByCount.end())
		{
			iter->second.first += iCount;
			iter->second.second += iCount;
		}
	}
	else
	{
		pBookList->push_back(CBook::Create(strAuthor, strTitle));
		m_LibraryByCount.emplace(strTitle, make_pair(iCount, iCount));
	}

	return S_OK;
}

list<class CBook*>* CBook_Manager::Find_BookList(string strAuthor)
{
	auto iter = m_Library.find(strAuthor);

	if (iter == m_Library.end())
		return nullptr;

	return &(iter->second);
}

CBook* CBook_Manager::Find_Book(list<class CBook*>* pBookList, string strTitle)
{
	for (auto iter : *pBookList)
	{
		if (strTitle == iter->Get_Title())
			return iter;
	}
	
	return nullptr;
}


CBook_Manager* CBook_Manager::Create()
{
	CBook_Manager* pInstance = new CBook_Manager();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CBook_Manager"));
		Safe_Release(pInstance);
	}

	return pInstance;
}


void CBook_Manager::Free()
{
	__super::Free();

}


