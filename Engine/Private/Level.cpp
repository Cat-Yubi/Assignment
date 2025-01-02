#include "Level.h"
#include "GameInstance.h"

CLevel::CLevel()
	: m_pGameInstance{ CGameInstance::Get_Instance() }
{
	Safe_AddRef(m_pGameInstance);
}

HRESULT CLevel::Initialize()
{
	return S_OK;
}

void CLevel::Update(_float fTimeDelta)
{
}

HRESULT CLevel::Render(_float fTimeDelta)
{
	return S_OK;
}

HRESULT CLevel::Clear_Resources()
{
	return m_pGameInstance->Clear_LevelResources(m_iLevelIndex);
}

void CLevel::Free()
{
	__super::Free();

	Safe_Release(m_pGameInstance);
}
