// 9.5 : Quadratic Equations Class
// Quadratic class header file
// +. operator overloading을 이용하여 add와 substract를 대체

#pragma once
#include <string>

class Quadratic
{
public:
	Quadratic(int a, int b, int c);
	Quadratic operator+(const Quadratic&);
	Quadratic operator-(const Quadratic&);
	std::string toString() const;
	int solve(char);
private:
	int A;
	int B;
	int C;
};