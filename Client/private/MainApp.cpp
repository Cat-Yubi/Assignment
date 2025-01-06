#include "MainApp.h"

#include "GameInstance.h"

#include "Level_Logo.h"

CMainApp::CMainApp()
	: m_pGameInstance{ CGameInstance::Get_Instance() }
{
	Safe_AddRef(m_pGameInstance);
}

HRESULT CMainApp::Initialize()
{ 
    if (FAILED(m_pGameInstance->Initialize_Engine(LEVEL_END)))
        return E_FAIL;

	if (FAILED(Open_Level()))
		return E_FAIL;

    return S_OK;
}

void CMainApp::Update(_float fTimeDelta)
{
	if (GetKeyState(VK_ESCAPE) & 0x8000)
		m_bCheckQuit = false;

	//if ((m_pGameInstance->Get_CurrentLevel_Index() != LEVEL_LOGO) && (GetKeyState(VK_ESCAPE) & 0x8000))
	//	m_pGameInstance->Change_Level(CLevel_Logo::Create());

	//cout << "Esc : Á¾·á			F1 : return Level_Logo" << endl;

    m_pGameInstance->Update_Engine(fTimeDelta);
}

HRESULT CMainApp::Render(_float fTimeDelta)
{
	m_pGameInstance->Render_Engine(fTimeDelta);
    return S_OK;
}

HRESULT CMainApp::Open_Level()
{
	if (FAILED(m_pGameInstance->Change_Level(CLevel_Logo::Create())))
		return E_FAIL;

	return S_OK;
}

CMainApp* CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CMainApp"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CMainApp::Free()
{
    m_pGameInstance->Release_Engine();
    Safe_Release(m_pGameInstance);
}
