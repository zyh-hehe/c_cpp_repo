#pragma once
#include<stdexcept>
#include<string>

using std::string;
using std::exception;

class FileException :public exception {
public:
	FileException() = default;
	const char* what() const override {
		return "File does not exist";
	}
};

class ColorException :public exception {
public:
	ColorException() = default;
	const char* what() const override {
		return "RGB value is invalid";
	}
};

class IDException :public exception {
public:
	IDException() = default;
	const char* what() const override {
		return "ID is out of range";
	}
};

class DataException :public exception {
public:
	DataException() = default;
};

class DataLackException :public DataException {
public:
	DataLackException() = default;
	const char* what()const override {
		return "Some data is missing";
	}
};

class DataSuperfluousException :public DataException {
public:
	DataSuperfluousException() = default;
	const char* what()const override {
		return "Some data is Superfluous";
	}
};
