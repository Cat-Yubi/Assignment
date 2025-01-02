#include "Level_Array.h"

#include "GameInstance.h"

CLevel_Array::CLevel_Array()
	: CLevel{}
{
}

HRESULT CLevel_Array::Initialize()
{
	m_iLevelIndex = LEVEL_ARRAY;

	return S_OK;
}

void CLevel_Array::Update(_float fTimeDelta)
{

	/*	if (GetKeyState(VK_RETURN) & 0x8000)
		{

		}*/
}

HRESULT CLevel_Array::Render(_float fTimeDelta)
{

	return S_OK;
}

CLevel_Array* CLevel_Array::Create()
{
	CLevel_Array* pInstance = new CLevel_Array();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CLevel_Array"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLevel_Array::Free()
{
	__super::Free();
}
