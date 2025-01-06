#include "Level_Input.h"

#include "GameInstance.h"

CLevel_Input::CLevel_Input()
	: CLevel{}
{
}

HRESULT CLevel_Input::Initialize()
{
	m_iLevelIndex = LEVEL_INPUT;

	return S_OK;
}

void CLevel_Input::Update(_float fTimeDelta)
{
	if (m_pNumArray != nullptr)
		return;

	_int iNumInput = 0;
	cout << "1. 5개 숫자 입력하기	2. 원하는 숫자 입력하기" << endl;

	while (iNumInput != 1 && iNumInput != 2)
		cin >> iNumInput;

	if (iNumInput == 1)
	{
		m_pNumArray = new _int[5];
		m_iArrayLength = 5;
		cout << "숫자를 입력하세요." << endl;
		for (size_t i = 0; i < 5; i++)
			cin >> m_pNumArray[i];
	}
	else
	{
		_int ArrayLength = 0;
		cout << "배열 개수를 입력해주세요." << endl;

		while (ArrayLength <= 0)
			cin >> ArrayLength;

		m_pNumArray = new _int[ArrayLength];
		m_iArrayLength = ArrayLength;

		cout << "숫자를 입력하세요." << endl;
		for (size_t i = 0; i < 5; i++)
			cin >> m_pNumArray[i];
	}

}

HRESULT CLevel_Input::Render(_float fTimeDelta)
{
	if (m_pNumArray == nullptr)
		return S_OK;

	_int iNumInput = 0;
	cout << "1.합 2.평균 3.오름차순 4.내림차순" << endl;

	while (iNumInput <= 0 || iNumInput > 4)
		cin >> iNumInput;
	
	switch (iNumInput)
	{
	case 1:	case 2:
		cout << "결과는 " << (iNumInput == 1 ? ArrayFunc(false) : ArrayFunc(true)) << " 입니다." << endl;
		break;
	case 3:

		cout << "실행 전 :" << endl;
		for (_int i = 0; i < m_iArrayLength; i++)
			cout << m_pNumArray[i] << " ";
		cout << endl;

		for (_int i = 0; i < m_iArrayLength - 1; ++i)
		{
			_int iMinIndex = i;
			for (_int j = i + 1; j < m_iArrayLength; ++j)
			{
				if (m_pNumArray[j] < m_pNumArray[iMinIndex])
					iMinIndex = j;
			}

			_int iTemp = m_pNumArray[i];
			m_pNumArray[i] = m_pNumArray[iMinIndex];
			m_pNumArray[iMinIndex] = iTemp;
		}

		cout << "실행 후 :" << endl;
		for (_int i = 0; i < m_iArrayLength; i++)
			cout << m_pNumArray[i] << " ";

		break;
	case 4:

		cout << "실행 전 :" << endl;
		for (_int i = 0; i < m_iArrayLength; i++)
			cout << m_pNumArray[i] << " ";
		cout << endl;

		for (_int i = 0; i < m_iArrayLength - 1; ++i)
		{
			_int iMinIndex = i;
			for (_int j = i + 1; j < m_iArrayLength; ++j)
			{
				if (m_pNumArray[j] > m_pNumArray[iMinIndex])
					iMinIndex = j;
			}

			_int iTemp = m_pNumArray[i];
			m_pNumArray[i] = m_pNumArray[iMinIndex];
			m_pNumArray[iMinIndex] = iTemp;
		}

		cout << "실행 후 :" << endl;
		for (_int i = 0; i < m_iArrayLength; i++)
			cout << m_pNumArray[i] << " ";

		break;
	}

	
	getchar();
	getchar();
	return S_OK;
}

HRESULT CLevel_Input::Ready_Texts()
{

	return S_OK;
}

_int CLevel_Input::ArrayFunc(_bool bAverage)
{
	_int iNumber = 0;

	for (_int i = 0; i < m_iArrayLength; i++)
		iNumber += m_pNumArray[i];

	if (bAverage == false)	return iNumber;
	else					return iNumber / m_iArrayLength;
}

CLevel_Input* CLevel_Input::Create()
{
	CLevel_Input* pInstance = new CLevel_Input();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CLevel_Input"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLevel_Input::Free()
{
	__super::Free();

	Safe_Delete_Array(m_pNumArray);
}
