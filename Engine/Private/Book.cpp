#include "Book.h"
#include "GameInstance.h"

CBook::CBook()
	: m_pGameInstance{ CGameInstance::Get_Instance() }
{
	Safe_AddRef(m_pGameInstance);
}

HRESULT CBook::Initialize(string strAuthor, string strTitle)
{
	m_strTitle = strTitle;
	m_strAuthor = strAuthor;
	return S_OK;
}

void CBook::Update(_float fTimeDelta)
{
}

HRESULT CBook::Render(_float fTimeDelta)
{
	return S_OK;
}

HRESULT CBook::Ready_Texts()
{
	return S_OK;
}

CBook* CBook::Create(string strAuthor, string strTitle)
{
	CBook* pInstance = new CBook();

	if (FAILED(pInstance->Initialize(strAuthor, strTitle)))
	{
		MSG_BOX(TEXT("Failed to Created : CBook_Manager"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CBook::Free()
{
	__super::Free();

	Safe_Release(m_pGameInstance);
}
