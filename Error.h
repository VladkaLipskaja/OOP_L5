#ifndef Error_h
#define Error_h
#include <iostream>
using namespace std;

class Error {
public:
	float x, y, z;
	virtual void ErrorPrint() { cout << "Error!" << endl; }
};

class StrangeSymbols : public Error {
public:
	void ErrorPrint() { cout << "There is no just float number, it is a string!" << endl; }
};

class Points : public Error {
public:
	void ErrorPrint() { cout << "There are a lot of points!" << endl; }
};

class OverFlow : public Error {
public:
	void ErrorPrint() { cout << "Overflow!" << endl; }
};
#endif