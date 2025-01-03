#pragma once

#pragma warning (disable : 4251)

#include <unordered_map>
#include <winerror.h>
#include <Windows.h>
#include <iostream>
#include <winnt.h>
#include <map>

using namespace std;

#include "Engine_Macro.h"
#include "Engine_Struct.h"
#include "Engine_TypeDef.h"
#include "Engine_Function.h"

namespace Engine
{

}

using namespace Engine;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif // _DEBUG

