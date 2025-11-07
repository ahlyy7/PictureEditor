// DegreesRadiansChange.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "degreesradianschange.h"
#include <numbers>

double degrees_to_radians(double degrees)
{
	return degrees * (std::numbers::pi / 180.0);
}

double radians_to_degrees(double radians)
{
	return radians * (180.0 / std::numbers::pi);
}
