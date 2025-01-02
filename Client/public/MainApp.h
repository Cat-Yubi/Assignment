#pragma once
#include "Client_Defines.h"
#include "Base.h"

BEGIN(Engine)
class CGameInstance;
END

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize();
	void Update(_float fTimeDelta);
	HRESULT Render(_float fTimeDelta);

public:
	_bool Check_QuitGame() const { return m_bCheckQuit; }
private:
	HRESULT Open_Level(LEVELID eStartLevelID);

	CGameInstance* m_pGameInstance = { nullptr };

	_bool m_bCheckQuit = { true };
public:
	static CMainApp* Create();
	virtual void Free() override;
};
