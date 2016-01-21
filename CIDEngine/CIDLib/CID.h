#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <string>

#include "CSingleton.h"

namespace CID
{
	template <typename T>
	inline T log(T say)
	{
		printf("%\ns", say);
		return 0;
	}

	template <typename T>
	inline T CIDLog(T say, T say2)
	{
		printf("[ System ] : %s : %s\n", say, say2);
		return 0;
	}

}