#include "Level_Array.h"

#include "GameInstance.h"
#include "SimpleVector.h"
CLevel_Array::CLevel_Array()
	: CLevel{}
{
}

HRESULT CLevel_Array::Initialize()
{
	m_iLevelIndex = LEVEL_ARRAY;

	if (FAILED(Ready_Texts()))
		return E_FAIL; 

	CSimpleVector<int> vec(3);
	vec[1] = 1;
	
	
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
	m_pGameInstance->Render_Text(m_iLevelIndex, 0);

	return S_OK;
}

HRESULT CLevel_Array::Ready_Texts()
{
	if (FAILED(m_pGameInstance->Add_Text(m_iLevelIndex, 0, R"(¤±¤±¤±)")))
		return E_FAIL;

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
