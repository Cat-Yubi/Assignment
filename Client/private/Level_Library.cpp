#include "Level_Library.h"

#include "GameInstance.h"

CLevel_Library::CLevel_Library()
	: CLevel{}
{
}

HRESULT CLevel_Library::Initialize()
{
	m_iLevelIndex = LEVEL_LIBRARY;

	if (FAILED(Ready_Books()))
		return E_FAIL; 

	return S_OK;
}

void CLevel_Library::Update(_float fTimeDelta)
{

}

HRESULT CLevel_Library::Render(_float fTimeDelta)
{
	_int iNumInput = 0;
	cout << "1. 검색 2. 빌리기";
	cin >> iNumInput;

	if (iNumInput == 1)
	{
		cout << "1. 작가 검색\t2. 책 검색\t3. 전체 검색" << endl;
		cin >> iNumInput;

		if (iNumInput == 1)
		{
			cout << "입력해주세요." << endl;
			string strAuthor;

			cin >> strAuthor;

			m_pGameInstance->DisplayBook(strAuthor);
		}
		else if (iNumInput == 2)
		{
			cout << "입력해주세요." << endl;
			string strTitle;

			cin >> strTitle;

			m_pGameInstance->DisplayBook("", strTitle);
		}
		else
		{
			m_pGameInstance->DisplayBook();
		}
	}
	else
	{
		cout << "입력해주세요." << endl;

		string strTitle;

		cin >> strTitle;

		m_pGameInstance->BorrowBook(strTitle);
	}
	cin.get();
	cin.get();

	return S_OK;
}

HRESULT CLevel_Library::Ready_Texts()
{

	return S_OK;
}

HRESULT CLevel_Library::Ready_Books()
{
	m_pGameInstance->Add_Book("A", "AA", 10);
	m_pGameInstance->Add_Book("A", "AB", 10);
	m_pGameInstance->Add_Book("A", "AC", 10);
	m_pGameInstance->Add_Book("A", "AD", 10);
	m_pGameInstance->Add_Book("B", "BA", 10);
	m_pGameInstance->Add_Book("B", "BB", 10);
	m_pGameInstance->Add_Book("B", "BC", 10);
	m_pGameInstance->Add_Book("B", "BD", 10);
	m_pGameInstance->Add_Book("C", "CA", 10);
	m_pGameInstance->Add_Book("C", "CB", 10);
	m_pGameInstance->Add_Book("C", "CC", 10);
	m_pGameInstance->Add_Book("C", "CD", 10);
	m_pGameInstance->Add_Book("D", "DA", 10);
	m_pGameInstance->Add_Book("D", "DB", 10);
	m_pGameInstance->Add_Book("D", "DC", 10);
	m_pGameInstance->Add_Book("D", "DD", 10);
	return S_OK;
}

CLevel_Library* CLevel_Library::Create()
{
	CLevel_Library* pInstance = new CLevel_Library();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CLevel_Library"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLevel_Library::Free()
{
	__super::Free();
}
