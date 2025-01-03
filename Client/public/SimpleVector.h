#pragma once
#include "Base.h"

template <typename T>
class CSimpleVector : public CBase
{
private:
	CSimpleVector();
	virtual ~CSimpleVector() = default;

	HRESULT Initialize(_int iCapacity);
public:
	void Push_Back(const T& data);
	T& operator[](_int index);
	T& At(_int index);        
	_int Size() const;        
	_int Capacity() const;    
	void Clear();             
	void Resize(_int newCapacity);

private:
	T* m_Data = { nullptr };
	_int m_iCurrentSize = { 0 };
	_int m_iCapacity = { 10 };

public:
	static CSimpleVector* Create(_int iCapacity = 10);
	void Free();
};

template<typename T>
CSimpleVector<T>::CSimpleVector()
{

}

template<typename T>
HRESULT CSimpleVector<T>::Initialize(_int iCapacity)
{
	m_Data = new T[iCapacity];

	m_iCurrentSize = 0;
	m_iCapacity = iCapacity;

	return S_OK;
}

template <typename T>
void CSimpleVector<T>::Push_Back(const T& data)
{
	if (m_iCurrentSize >= m_iCapacity)
		Resize(m_iCapacity * 2);

	m_Data[m_iCurrentSize++] = data;
}

template <typename T>
void CSimpleVector<T>::Resize(_int newCapacity)
{
	if (newCapacity <= m_iCapacity)
		return;

	T* newData = new T[newCapacity];

	for (_int i = 0; i < m_iCurrentSize; ++i)
		newData[i] = m_Data[i];

	Safe_Delete_Array(m_Data);

	m_Data = newData;
	m_iCapacity = newCapacity;
}

template <typename T>
T& CSimpleVector<T>::At(_int index) 
{
    if (index < 0 || index >= m_iCurrentSize)
        throw std::out_of_range("Index out of range");
    
    return m_Data[index];
}

template <typename T>
T& CSimpleVector<T>::operator[](_int index) 
{
    return At(index);
}

template <typename T>
_int CSimpleVector<T>::Size() const
{
	return m_iCurrentSize;
}

template <typename T>
_int CSimpleVector<T>::Capacity() const
{
	return m_iCapacity;
}

template <typename T>
void CSimpleVector<T>::Clear()
{
	m_iCurrentSize = 0;
}

template<typename T>
CSimpleVector<T>* CSimpleVector<T>::Create(_int iCapacity)
{
	CSimpleVector<T>* pinstance = new CSimpleVector<T>();

	if (FAILED(pinstance->Initialize(iCapacity)))
	{
		MSG_BOX(TEXT("Failed to Created : CLevel_Logo"));
		Safe_Release(pinstance);
	}

	return pinstance;
}

template<typename T>
void CSimpleVector<T>::Free()
{
	Safe_Delete_Array(m_Data);
}



