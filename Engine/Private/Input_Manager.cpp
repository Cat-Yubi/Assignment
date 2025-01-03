#include "Input_Manager.h"

CInput_Manager::CInput_Manager()
{
}

HRESULT CInput_Manager::Initailize(_uint iNumLevels)
{
	m_iNumLevels = iNumLevels;

	m_pStrings = new map<const string, const _char*>[iNumLevels];

	return S_OK;
}

HRESULT CInput_Manager::Add_Text(_uint iNumLevel, string strTag, const _char* strName)
{
	if (iNumLevel >= m_iNumLevels)
		return E_FAIL;

	m_pStrings[iNumLevel].emplace(strTag, strName);

	return S_OK;
}

HRESULT CInput_Manager::Render_Text(_uint iNumLevel, string strTag)
{
	auto iter = m_pStrings[iNumLevel].find(strTag);

	if (iter == m_pStrings[iNumLevel].end())
		return E_FAIL;

	cout << iter->second << endl;

	return S_OK;
}

CInput_Manager* CInput_Manager::Create(_uint iNumLevels)
{
	CInput_Manager* pInstance = new CInput_Manager();

	if (FAILED(pInstance->Initailize(iNumLevels)))
	{
		MSG_BOX(TEXT("Failed to Created : CInput_Manager"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CInput_Manager::Free()
{
	__super::Free();

	for (size_t i = 0; i < m_iNumLevels; i++)
	{
		//for (auto& Pair : m_pStrings[i])
		//	Safe_Release(Pair.second);

		m_pStrings[i].clear();
	}
}