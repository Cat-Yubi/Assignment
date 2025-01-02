#pragma once

#include "Engine_Defines.h"

/* ��� Ŭ������ �θ� �Ǳ����� Ŭ�����̴�. */
/* ���۷��� ī��Ʈ�� ����(AddRef, Release)�Ѵ�. */
BEGIN(Engine)

class ENGINE_DLL CBase abstract
{
protected:
	CBase();
	virtual ~CBase() = default;

public:
	/* RefCnt ���� */
	_uint AddRef() { return ++m_iRefCnt; }

	/* RefCnt ���� || ���� */
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

