#include "Level_Logo.h"

#include "GameInstance.h"

CLevel_Logo::CLevel_Logo()
	: CLevel{}
{
}

HRESULT CLevel_Logo::Initialize()
{
	m_iLevelIndex = LEVEL_LOGO;

	cout << "Press Enter" << endl << endl;

	if (FAILED(Ready_Texts()))
		return E_FAIL;

	return S_OK;
}

void CLevel_Logo::Update(_float fTimeDelta)
{
	if (GetKeyState(VK_RETURN) & 0x8000)
		m_bisStart = true;

	if (m_bisStart == true)
	{
		/*cout << m_tLogo	<< endl;*/
	}

}

HRESULT CLevel_Logo::Render(_float fTimeDelta)
{
	m_pGameInstance->Render_Text(m_iLevelIndex, 0);

	return S_OK;
}

HRESULT CLevel_Logo::Ready_Texts()
{
	if (FAILED(m_pGameInstance->Add_Text(m_iLevelIndex, 0, R"(
	` `   `       ` ` ``                                                              ``            ` `  `  `                       ``               ``                                  
	`   `         ` `` `                                                            ```             ` `   `                        `##`             `           `                        
	  ##` `       `##  `                                                            `##          `` `########``  ` ````````` `   `  ## `           `##########```   `#################   
	  ##` `       `##  `                                                            `##          ``### ` `` ##`  `###########`   `  ##           ```##`       ``     ```   `##` `   ```  
	  ##` `       `##  ` ``````##``     ````` `### `` ` ``##`  ``   ` ` `##```  `   `##          `  ` ``    `##           `##`   `  ##`            `##                      ##```        
	  ##` `       `##  ` #####` `###```  `####````   `###` `####   ` `##`` `###`    `##                    `###         ` ##``   `  ##`             ## ``#`` ``           `####`` ``     
	  ##` `       `##  ` ### `   ``##` ` `##``` ` ` ### `` ` ``##``` `  `  `  ##`   `##                    `##  `        ##`     `  ##`            `###````###` `        ###  ###`       
	  ##` `       `##  ` ##```     ##`   `##`     ``##` `````` `##   ``` `````##`   `##                 ``##`         ``##`      `  ##`           ``` ``     ##``   ` `###`     ###`     
	  ##``       ``##    ##```     ##`   `##       `##############`  `####````##`   `##               ` ###``    `    ### `      `  ##`                      `##` ` ####`   ` `   `####` 
	  ###``       `##  ` ##```     ##`   `##      ` ##``         ` `###  `  ``##`   `##             ` ### ` `      `###`  `      `  ##`                    ``###  ` `` `  ``##` ` ` `` ` 
	   ###``` ` ``##     ##```     ##`   `##        `###`  ``` #`   ### `   ``##`   `##           ``### ``    `  ####  `         `  ##`          `` `` ` `` ###``          `##`         `
	`   `#########`  `   ##```     ##`   `##        ` `#########   ```##########`   `##            ############`  ` `  `         `  ##`           ``#########````########################
	     `      `` `    `    `    `  ``  ``         ` ``   ``  `      ``     ```     ``          ``             `                `  ##`             `` ` ` ` ``  ``````````````````````` 
                                                                                                                                       `##
)")))	return E_FAIL;
		
	return S_OK;
}

CLevel_Logo* CLevel_Logo::Create()
{
	CLevel_Logo* pInstance = new CLevel_Logo();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed to Created : CLevel_Logo"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLevel_Logo::Free()
{
	__super::Free();
}
