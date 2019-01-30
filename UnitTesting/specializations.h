#pragma once
#include "stdafx.h"
#include "../blocksolver/Point.h"

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<class Point<2>>(const class Point<2>& t)
			{
				std::wstringstream out = std::wstringstream();
				out << "Point(" << t[0] << ", " << t[1] << ")";

				return out.str();
			}

			template<> static std::wstring ToString<class Point<3>>(const class Point<3>& t)
			{
				std::wstringstream out = std::wstringstream();
				out << "Point(" << t[0] << ", " << t[1] << ", " << t[2] << ")";

				return out.str();
			}
		}
	}
}