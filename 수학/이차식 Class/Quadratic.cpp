// 9.5 : Quadratic Equations Class
// Quadratic class의 함수 정의
// +. operator overloading을 이용하여 add와 substract를 대체

#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // for ostringstream
#include <stdexcept> // for handling invalid_argument exception 
#include "Quadratic.h"

using namespace std;

Quadratic::Quadratic(int a, int b, int c) : B(b), C(c)
{
	if (a != 0)
	{
		A = a;
	}
	else
	{
		cout << "a의 값은 0이 아니여야 합니다." << '\n';
		cout << "a = 1로 초기화합니다." << "\n\n";
		A = 1;
	}
}

Quadratic Quadratic::operator+(const Quadratic& Q)
{
	Quadratic result{this->A, this->B, this->C};
	result.A += Q.A; result.B += Q.B; result.C += Q.C;
	return result;
}

Quadratic Quadratic::operator-(const Quadratic& Q)
{
	Quadratic result{ this->A, this->B, this->C };
	result.A -= Q.A; result.B -= Q.B; result.C -= Q.C;
	return result;
}

string Quadratic::toString() const
{
	ostringstream output;

	if (A == 1)
	{
		output << "x^2";
	}
	else
	{
		output << A << "x^2";
	}

	if (B == 1)
	{
		output << "+x";
	}
	else if (B < 0)
	{
		output << B << "x";
	}
	else if (B != 0)
	{
		output << "+" << B << "x";
	}

	if (C < 0)
	{
		output << C;
	}
	else if (C != 0)
	{
		output << "+" << C;
	}

	output << " = 0";
	return output.str();
}

int Quadratic::solve(char sign)
{
	double discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
	{
		throw invalid_argument("이차식에 실근이 존재하지 않습니다.");
	}
	else
	{
		double numer;
		if (sign == '+')
		{
			numer = - B + sqrt(discriminant);
		}
		else if (sign == '-')
		{
			numer = - B - sqrt(discriminant);
		}
		else
		{
			throw invalid_argument("올바른 부호가 입력되지 않았습니다.");
		}

		double deno = 2 * A;
		return numer / deno;
	}
}
