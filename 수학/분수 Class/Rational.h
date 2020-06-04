// 9.6 : Rational Class
// Rational class header file
// +. 연산자 오버로딩(+, -, *, /, ++, --, >>, <<) 이용

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational
{
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);

private:
	int numerator;
	int denominator;
	void setRational(int, int);

public:
	Rational(int = 1, int = 1);

	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);

	Rational operator++();
	Rational& operator++(int);
	Rational operator--();
	Rational& operator--(int);

	double getdouble() const;
};

#endif
