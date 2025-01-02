#include "GameInstance.h"
#include "MainApp.h"

void SetConsoleSize(_int width, _int height, _int bufferWidth, _int bufferHeight);

int main()
{
	//SetConsoleSize(1920, 1080, 1920, 1080);

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

void SetConsoleSize(_int width, _int height, _int bufferWidth, _int bufferHeight)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == nullptr)
		return;

	if (bufferWidth > 0 && bufferHeight > 0)
	{
		COORD bufferSize;
		bufferSize.X = bufferWidth;
		bufferSize.Y = bufferHeight;
		SetConsoleScreenBufferSize(hConsole, bufferSize);
	}

	SMALL_RECT windowSize;
	windowSize.Left = 0;
	windowSize.Top = 0;
	windowSize.Right = width - 1;
	windowSize.Bottom = height - 1;

	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}
