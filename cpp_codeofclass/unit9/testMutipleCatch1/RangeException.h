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
	//������һ�����࣬�����������Ҳ��what����(�麯��)
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
	const char* what() const//���what�����ǻ���what����(�麯��)���ض��壬�ڵ���ʱ����ݲ������������;��������ĸ��麯��
	{
		return "index is out of Vec3D's dimension!";
	}
};