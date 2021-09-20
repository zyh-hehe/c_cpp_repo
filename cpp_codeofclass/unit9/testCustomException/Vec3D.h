#pragma once
#include<iostream>
#include<array>
#include"RangeException.h"
using namespace std;
class Vec3D
{
private:
	std::size_t dimension{ 3 };
	std::array<double, 3> v{ 1.0,1.0,1.0 };
public:
	Vec3D() = default;
	Vec3D(double x, double y, double z)
	{
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}
	double& operator[](int index)
	{
		if (index >= 0 && index < dimension)
			return v[index];
		else
			throw RangeException(dimension, index) ;
	}
};
