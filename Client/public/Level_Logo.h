#pragma once

#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_Logo final : public CLevel
{
private:
	CLevel_Logo();
	virtual ~CLevel_Logo() = default;

public:
	virtual HRESULT Initialize() override;
	virtual void Update(_float fTimeDelta) override;
	virtual HRESULT Render(_float fTimeDelta) override;
	virtual HRESULT Ready_Texts() override;

private:
	_bool m_bisStart = { false };
	const _char* m_tLogo;
public:
	static CLevel_Logo* Create();
	virtual void Free() override;
};

END