#include "GameInstance.h"
#include "MainApp.h"

void SetConsoleSize(int width, int height);

int main()
{
	//SetConsoleSize(1920, 1080);
	//getchar();
	//SetConsoleSize(1920, 1080);
	//HWND hwnd = GetConsoleWindow();
	//if (hwnd) {
	//	// 콘솔 창 크기 설정
	//	MoveWindow(hwnd, 100, 100, 800, 600, TRUE);  // (x, y, width, height)
	//}
	//system("mode con");
	//system("mode con cols=300 lines=70 | title 제목명");
	//getchar();
	//system("mode con");
	//getchar();
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

void SetConsoleSize(int width, int height) {
	// Get the console window handle
	HWND hwnd = GetConsoleWindow();
	if (hwnd) {
		// Set the console size (width x height)
		MoveWindow(hwnd, 100, 100, width, height, TRUE);
	}
	else {
		std::cout << "Failed to get console window handle!" << std::endl;
	}
}
