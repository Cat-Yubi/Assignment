#pragma once

#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_Library final : public CLevel
{
private:
	CLevel_Library();
	virtual ~CLevel_Library() = default;

public:
	virtual HRESULT Initialize() override;
	virtual void Update(_float fTimeDelta) override;
	virtual HRESULT Render(_float fTimeDelta) override;
	virtual HRESULT Ready_Texts() override;

	HRESULT Ready_Books();
public:
	static CLevel_Library* Create();
	virtual void Free() override;
};

END