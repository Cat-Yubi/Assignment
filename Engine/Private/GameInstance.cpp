#include "GameInstance.h"

#include "Level_Manager.h"
#include "Timer_Manager.h"
#include "Input_Manager.h"
#include "Book_Manager.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
{

}


HRESULT CGameInstance::Initialize_Engine(_uint iNumLevels)
{
	m_pLevel_Manager = CLevel_Manager::Create();
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	m_pTimer_Manager = CTimer_Manager::Create();
	if (nullptr == m_pTimer_Manager)
		return E_FAIL;

	m_pInput_Manager = CInput_Manager::Create(iNumLevels);
	if (nullptr == m_pInput_Manager)
		return E_FAIL;

	m_pBook_Manager = CBook_Manager::Create();
	if (nullptr == m_pBook_Manager)
		return E_FAIL;

    return S_OK;
}

void CGameInstance::Update_Engine(_float fTimeDelta)
{
    m_pLevel_Manager->Update(fTimeDelta);
}

HRESULT CGameInstance::Render_Engine(_float fTimeDelta)
{
    if (FAILED(m_pLevel_Manager->Render(fTimeDelta)))
        return E_FAIL;

    return S_OK;
}

HRESULT CGameInstance::Clear_LevelResources(_uint iLevelIndex)
{
	/* 당장은 없음 */
    return S_OK;
}

HRESULT CGameInstance::Change_Level(CLevel* pNewLevel)
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Change_Level(pNewLevel);
}

_uint CGameInstance::Get_CurrentLevel_Index()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Get_CurrentLevel_Index();
}

_uint CGameInstance::Get_LoadingLevel_Index()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Get_LoadingLevel_Index();
}

HRESULT CGameInstance::Set_LoadingLevel_Index(_uint iLevel)
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Set_LoadingLevel_Index(iLevel);
}

CLevel* CGameInstance::Get_Level()
{
	if (nullptr == m_pLevel_Manager)
		return nullptr;

	return m_pLevel_Manager->Get_Level();
}

HRESULT CGameInstance::Add_Timer(const _wstring& strTimerTag)
{
	return m_pTimer_Manager->Add_Timer(strTimerTag);
}

_float CGameInstance::Compute_TimeDelta(const _wstring& strTimerTag)
{
	return m_pTimer_Manager->Compute_TimeDelta(strTimerTag);
}

HRESULT CGameInstance::Add_Text(_uint iNumLevel, string strTag, const _char* strName)
{
	return m_pInput_Manager->Add_Text(iNumLevel, strTag, strName);
}

HRESULT CGameInstance::Render_Text(_uint iNumLevel, string strTag)
{
	return m_pInput_Manager->Render_Text(iNumLevel, strTag);
}

void CGameInstance::DisplayBook(string strAuthor, string strTitle)
{
	m_pBook_Manager->DisplayBook(strAuthor, strTitle);
}

void CGameInstance::DisplayBorrowBook(string strAuthor, string strTitle)
{
	m_pBook_Manager->DisplayBorrowBook(strAuthor, strTitle);
}

CBook* CGameInstance::BorrowBook(string strTitle)
{
	return m_pBook_Manager->BorrowBook(strTitle);
}

HRESULT CGameInstance::Add_Book(string strAuthor, string strTitle, _int iCount)
{
	return m_pBook_Manager->Add_Book(strAuthor, strTitle, iCount);
}

void CGameInstance::Release_Engine()
{
	Safe_Release(m_pLevel_Manager);
	Safe_Release(m_pTimer_Manager);
	Safe_Release(m_pInput_Manager);
	Safe_Release(m_pBook_Manager);

	CGameInstance::Get_Instance()->Destroy_Instance();
}

void CGameInstance::Free()
{
	__super::Free();
}
