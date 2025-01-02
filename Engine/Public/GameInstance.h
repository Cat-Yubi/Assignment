#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)
private:
	CGameInstance();
	virtual ~CGameInstance() = default;
	
public:
	HRESULT Initialize_Engine(_uint iNumLevels);
	void Update_Engine(_float fTimeDelta);
	HRESULT Render_Engine(_float fTimeDelta);
	HRESULT Clear_LevelResources(_uint iLevelIndex);

public: /* For.Level_Manager */
	HRESULT Change_Level(class CLevel* pNewLevel);
	_uint	Get_CurrentLevel_Index();
	_uint	Get_LoadingLevel_Index();
	HRESULT Set_LoadingLevel_Index(_uint iLevel);
	class CLevel* Get_Level();

public: /* For.Timer_Manager */
	HRESULT Add_Timer(const _wstring& strTimerTag);
	_float Compute_TimeDelta(const _wstring& strTimerTag);

public: /* For.Input_Manager */
	HRESULT Add_Text(_uint iNumLevel, _uint iNumKey, const _char* strName);
	HRESULT Render_Text(_uint iNumLevel, _uint iNumKey);
	
private:
	class CLevel_Manager* m_pLevel_Manager = { nullptr };
	class CTimer_Manager* m_pTimer_Manager = { nullptr };
	class CInput_Manager* m_pInput_Manager = { nullptr };
public:
	void Release_Engine();

	virtual void Free() override;

};

END