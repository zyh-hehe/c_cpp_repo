#pragma once
#include<iostream>
class Square
{
private:
	double side;
public:
	static int numberofsquare;
	Square() :Square(1.0) {/*默认构造函数，使用了代理构造*/}
	Square(double side_) : side{ side_ } 
	{ 
		numberofsquare++; 
		std::cout << "Now there are(is) " << Square::numberofsquare << " square(s)" << std::endl;
	}
	double getSide() { return side ; }
	void setSide(double side) { this->side = side ; }
	Square(const Square& s)
	{
		this->side = s.side;
		numberofsquare++;
		std::cout << "copyctor function has been invoked" << std::endl;
		std::cout << "Now there are(is) " << Square::numberofsquare << " square(s)" << std::endl;
	}
	~Square()
	{ 
		numberofsquare--;
		std::cout << "Now there are(is) " << Square::numberofsquare << "square(s)" << std::endl;
	}
};