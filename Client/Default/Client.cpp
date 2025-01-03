#include "GameInstance.h"
#include "MainApp.h"

int main()
{
	CMainApp* pMainApp = CMainApp::Create();
	if (nullptr == pMainApp)
		return FALSE;

	CGameInstance* pGameInstance = CGameInstance::Get_Instance();
	if (nullptr == pGameInstance)
		return FALSE;

	if (FAILED(pGameInstance->Add_Timer(TEXT("Timer_Default"))))
		return FALSE;

	if (FAILED(pGameInstance->Add_Timer(TEXT("Timer_60"))))
		return FALSE;

	_float		fTimeAcc = { 0.f };

	while (pMainApp->Check_QuitGame())
	{
		fTimeAcc += pGameInstance->Compute_TimeDelta(TEXT("Timer_Default"));

		if (fTimeAcc >= 1.f / 60.0f)
		{
			system("cls");

			pMainApp->Update(pGameInstance->Compute_TimeDelta(TEXT("Timer_60")));
			pMainApp->Render(pGameInstance->Compute_TimeDelta(TEXT("Timer_60")));

			fTimeAcc = 0.f;
			
		}
	}

	Safe_Release(pGameInstance);
	Safe_Release(pMainApp);
}

