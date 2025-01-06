#pragma once

#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_Input final : public CLevel
{
private:
	CLevel_Input();
	virtual ~CLevel_Input() = default;

public:
	virtual HRESULT Initialize() override;
	virtual void Update(_float fTimeDelta) override;
	virtual HRESULT Render(_float fTimeDelta) override;
	virtual HRESULT Ready_Texts() override;

	_int ArrayFunc(_bool bAverage);
private:
	_int* m_pNumArray = { nullptr };
	_int m_iArrayLength = 0;
public:
	static CLevel_Input* Create();
	virtual void Free() override;
};

END