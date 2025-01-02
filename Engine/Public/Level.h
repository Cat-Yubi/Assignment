#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CLevel abstract : public CBase
{
protected:
	CLevel();
	virtual ~CLevel() = default;
	  
public:
	virtual HRESULT Initialize();
	virtual void Update(_float fTimeDelta);
	virtual HRESULT Render(_float fTimeDelta);
	virtual HRESULT Ready_Texts();
public:
	HRESULT Clear_Resources();
	_uint GetLevelIndex() const { return m_iLevelIndex; };

protected:
	class CGameInstance*			m_pGameInstance = { nullptr };
	_uint							m_iLevelIndex = { 0 };

public:
	virtual void Free() override;
};

END
