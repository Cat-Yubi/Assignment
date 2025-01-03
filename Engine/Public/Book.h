#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CBook : public CBase
{
private:
	CBook();
	virtual ~CBook() = default;
	  
public:
	virtual HRESULT Initialize(string strAuthor, string strTitle);
	virtual void Update(_float fTimeDelta);
	virtual HRESULT Render(_float fTimeDelta);
	virtual HRESULT Ready_Texts();
public:
	string Get_Title() { return m_strTitle; }
	string Get_Author() { return m_strAuthor; }

protected:
	class CGameInstance*			m_pGameInstance = { nullptr };
	string							m_strTitle = "";
	string							m_strAuthor = "";

public:
	static CBook* Create(string strAuthor, string strTitle);
	virtual void Free() override;
};

END
