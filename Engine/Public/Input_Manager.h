#pragma once

#include "Base.h"

BEGIN(Engine)

class CInput_Manager : public CBase
{
private:
	CInput_Manager(void);
	virtual ~CInput_Manager(void) = default;

public:
	HRESULT Initailize(_uint iNumLevels);

public:
	HRESULT Add_Text(_uint iNumLevel, string strTag, const _char* strName);
	HRESULT Render_Text(_uint iNumLevel, string strTag);
private:
	_uint							   m_iNumLevels	 = { 0 };
	map<const string, const _char*>* m_pStrings	 = { nullptr };

public:
	static CInput_Manager* Create(_uint iNumLevels);
	virtual void	Free(void);
};

END

