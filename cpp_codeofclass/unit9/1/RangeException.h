#pragma once
#include<exception>
class RangeException :public std::exception
{
private:
	std::size_t dimension{ 3 };
	int index{ 0 };
public:
	RangeException(std::size_t dimension, int index) 
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
	const char* what() const
	{
		return "index is out of Vec3D's dimension!";
	}
};