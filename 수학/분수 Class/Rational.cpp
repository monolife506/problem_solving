// 9.6 : Rational Class
// Rational Class내의 함수 정의
// +. 연산자 오버로딩(+, -, *, /, ++, --, >>, <<) 이용

#include <iostream>
#include <iomanip>
#include "Rational.h"
using namespace std;

// 계산의 편의를 위한 절대값을 씌운 두 숫자의 최소공약수를 구하는 함수
int absolute_GCD(int a, int b) 
{
	if (a == 0)
	{
		return 1;
	}

	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;

	while (b != 0) 
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

ostream& operator<<(std::ostream& output, const Rational& R)
{
	if (R.denominator == 1 || R.numerator == 0)
	{
		output << R.numerator;
	}
	else
	{
		output << R.numerator << '/' << R.denominator;
	}
	
	return output;
}

istream& operator>>(std::istream& input, Rational& R)
{
	int num; int deno;
	input >> num;
	input.ignore();
	input >> deno;

	R.setRational(num, deno);
	return input;
}

// Rational 객체의 numerator와 denominator값을 정하는 함수
void Rational::setRational(int numer, int deno)
{
	if (deno == 0)
	{
		cout << "분모는 0이 되어서는 안됩니다. 분모를 1로 초기화합니다." << '\n';
		deno = 1;
	}

	int gcd = absolute_GCD(numer, deno);
	numer /= gcd; deno /= gcd;

	numerator = numer;
	denominator = deno;
}

Rational::Rational(int numer, int deno)
{
	setRational(numer, deno);
}

Rational Rational::operator+(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator + this->denominator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator-(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator - this->denominator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator*(const Rational& R)
{
	Rational result
	{
		this->numerator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator/(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator,
		this->denominator * R.numerator
	};
	return result;
}

// Postfix
Rational Rational::operator++()
{
	setRational(numerator + denominator, denominator);
	return *this;
}


// Prefix
Rational& Rational::operator++(int)
{
	Rational temp{ *this };
	setRational(numerator + denominator, denominator);
	return temp;
}

// Postfix
Rational Rational::operator--()
{
	setRational(numerator - denominator, denominator);
	return *this;
}

// Prefix
Rational& Rational::operator--(int)
{
	Rational temp{ *this };
	setRational(numerator - denominator, denominator);
	return temp;
}

// 분자 / 분모의 값을 실수형으로 return하는 함수
double Rational::getdouble() const
{
	return static_cast<double>(numerator) / denominator;
}