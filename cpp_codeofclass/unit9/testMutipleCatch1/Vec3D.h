#pragma once
#include<iostream>
#include<array>
#include<cmath>
#include<limits>
#include"RangeException.h"
#include"ZeroException.h"
using namespace std;
class Vec3D
{
private:
	std::array<double, 3> v{ 1.0,1.0,1.0 };
	//������������������жϳ����Ƿ���0.0��ȣ����Ҿ���Ӧ��Ҳ����ֱ��д��(a-0.0)<1e-10
	bool isSame(double a, double b) {
		return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
	}
public:
	constexpr static std::size_t  DIMENSION{ 3 };//��ά����Ϊһ������������������������Ĵ�С
	Vec3D() = default;
	Vec3D(double x, double y, double z)
	{
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}
	double& operator[](int index)
	{
		if (index >= 0 && index < DIMENSION)
			return v[index];
		else
			throw RangeException(DIMENSION, index) ;
	}

	Vec3D operator / (double divisor) {
		if (isSame(divisor, 0.0))
			throw ZeroException();
		else 
			return Vec3D(v[0] / divisor, v[1] / divisor, v[2] / divisor);
	}
};
