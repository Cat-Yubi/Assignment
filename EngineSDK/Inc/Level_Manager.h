#pragma once

#include "Base.h"

BEGIN(Engine)

class CLevel_Manager final : public CBase
{
private:
	CLevel_Manager();
	virtual ~CLevel_Manager() = default;

public:
	HRESULT Initialize();
	void Update(_float fTimeDelta);
	HRESULT Render(_float fTimeDelta);

public:
	HRESULT Change_Level(class CLevel* pNewLevel);
	_uint Get_CurrentLevel_Index();
	_uint Get_LoadingLevel_Index();
	HRESULT Set_LoadingLevel_Index(_uint ilevel);
	CLevel* Get_Level() { return m_pCurrentLevel; };

private:
	class CLevel* m_pCurrentLevel = { nullptr };
	_uint m_iLoadingLevelIndex = { 0 };

public:
	static CLevel_Manager* Create();
	virtual void Free() override;
};

END