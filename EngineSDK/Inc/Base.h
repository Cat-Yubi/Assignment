#pragma once

#include "Engine_Defines.h"

/* 모든 클래스의 부모가 되기위한 클래스이다. */
/* 레퍼런스 카운트를 관리(AddRef, Release)한다. */
BEGIN(Engine)

class ENGINE_DLL CBase abstract
{
protected:
	CBase();
	virtual ~CBase() = default;

public:
	/* RefCnt 증가 */
	_uint AddRef() { return ++m_iRefCnt; }

	/* RefCnt 감소 || 삭제 */
	_uint Release()
	{
		if (0 == m_iRefCnt)
		{
			Free();

			delete this;

			return 0;
		}
		else
		{
			return m_iRefCnt--;
		}
	}

private:
	_uint m_iRefCnt = { 0 };

public:
	virtual void Free() {}
};

END

