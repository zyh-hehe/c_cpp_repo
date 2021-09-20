#pragma once
#include<exception>
#include<stdexcept>
class RangeException :public std::out_of_range
{
private:
	std::size_t dimension{ 3 };
	int index{ 0 };
public:
	RangeException(std::size_t dimension, int index) :out_of_range("index exceeds Vec3D's DIMENSION")
	//这里有一个基类，这个基类里面也有what函数(虚函数)
	{
		this->dimension = dimension;
		this->index = index;
	}
	std::size_t getDimension()
	{
		return dimension;
	}
	int getIndex()
	{
		return index;
	}
	const char* what() const//这个what函数是基类what函数(虚函数)的重定义，在调用时会根据参数的真正类型决定调用哪个虚函数
	{
		return "index is out of Vec3D's dimension!";
	}
};