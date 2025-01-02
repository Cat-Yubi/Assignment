#pragma once

#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_Array final : public CLevel
{
private:
	CLevel_Array();
	virtual ~CLevel_Array() = default;

public:
	virtual HRESULT Initialize() override;
	virtual void Update(_float fTimeDelta) override;
	virtual HRESULT Render(_float fTimeDelta) override;
	virtual HRESULT Ready_Texts() override;

public:
	static CLevel_Array* Create();
	virtual void Free() override;
};

END