#pragma once
#include<iostream>
#include<stdexcept>
#include<exception>

class ZeroException :public std::runtime_error {
public:
	ZeroException() :std::runtime_error("divided by 0.0") {};
	ZeroException(const char* msg) :std::runtime_error(msg) {};
};
