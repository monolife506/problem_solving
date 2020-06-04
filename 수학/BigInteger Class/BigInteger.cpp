// 9.14 && 10.9: Big Integer Class
// Big Integer Class 내의 함수들 정의

#include <iostream>
#include <array>
#include <string>
#include <cctype> // for isdigit()
#include "BigInteger.h"
using namespace std;

// 생성자
BigInteger::BigInteger(long long value)
{
	for (int i{digits - 1}; value != 0 && i >= 0; i--)
	{
		integer[i] = value % 10;
		value /= 10;
	}
}
BigInteger::BigInteger(const string& value)
{
	int length = value.size() ;
	for (int i{ digits - length }, j{ 0 }; i < digits; i++, j++)
	{
		if (isdigit(value[j]))
		{
			integer[i] = value[j] - '0';
		}
		else
		{
			throw invalid_argument("string은 자연수로 표현되지 않습니다.");
		}
	}
}

// '+' 연산자 오버로딩 
BigInteger BigInteger::operator+(const BigInteger& value) const
{
	BigInteger temp;
	int carry{ 0 };

	for (int i{ digits - 1 }; i >= 0; i--)
	{
		temp.integer[i] = this->integer[i] + value.integer[i] + carry;

		if (temp.integer[i] > 9)
		{
			carry = 1;
			temp.integer[i] %= 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}
BigInteger BigInteger::operator+(int value) const
{
	return *this + BigInteger(value); // BigInteger + BigInteger와 생성자 활용
}
BigInteger BigInteger::operator+(const string& value) const
{
	return *this + BigInteger(value); // BigInteger + BigInteger와 생성자 활용
}

// '-' 연산자 오버로딩
BigInteger BigInteger::operator-(const BigInteger& value) const
{
	BigInteger temp;
	int carry{ 0 };

	for (int i{ digits - 1 }; i >= 0; i--)
	{
		temp.integer[i] = this->integer[i] - value.integer[i] + carry;

		if (temp.integer[i] < 0)
		{
			carry = -1;
			temp.integer[i] = temp.integer[i] + 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}
BigInteger BigInteger::operator-(int value) const
{
	return *this - BigInteger(value); // BigInteger - BigInteger와 생성자 활용
}
BigInteger BigInteger::operator-(const string& value) const
{
	return *this - BigInteger(value); // BigInteger - BigInteger와 생성자 활용
}

// '*' 연산자 오버로딩
BigInteger BigInteger::operator*(const BigInteger& value) const
{
	static BigInteger temp;
	temp = 0;

	// BigInteger의 '+', '<' 연산자 오버로딩 활용
	for (BigInteger i; i < value; i = i + 1)
	{
		temp = temp + *this;
	}

	return temp;
}
BigInteger BigInteger::operator*(int value) const
{
	return *this * BigInteger(value); // BigInteger * BigInteger와 생성자 활용
}
BigInteger BigInteger::operator*(const string& value) const
{
	return *this * BigInteger(value); // BigInteger * BigInteger와 생성자 활용
}

// '/' 연산자 오버로딩
BigInteger BigInteger::operator/(const BigInteger& value) const
{
	static BigInteger temp;
	temp = *this;
	BigInteger i;

	// BigInteger의 '-', '>' 연산자 오버로딩 활용
	for (; temp >= value; i = i + 1)
	{
		temp = temp - value;
	}

	return i;
}
BigInteger BigInteger::operator/(int value) const
{
	return *this / BigInteger(value); // BigInteger / BigInteger와 생성자 활용
}
BigInteger BigInteger::operator/(const string& value) const
{
	return *this / BigInteger(value); // BigInteger / BigInteger와 생성자 활용
}

// '==' 연산자 오버로딩
bool BigInteger::operator==(const BigInteger& value) const
{
	return (this->integer == value.integer);
}
bool BigInteger::operator==(int value) const
{
	return (*this == BigInteger(value));
}
bool BigInteger::operator==(const string& value) const
{
	return (*this == BigInteger(value));
}

// '!=' 연산자 오버로딩
bool BigInteger::operator!=(const BigInteger& value) const
{
	return !(*this == value);
}
bool BigInteger::operator!=(int value) const
{
	return (*this != BigInteger(value));
}
bool BigInteger::operator!=(const string& value) const
{
	return (*this != BigInteger(value));
}

// '>' 연산자 오버로딩
bool BigInteger::operator>(const BigInteger& value) const
{
	return this->integer > value.integer;
}
bool BigInteger::operator>(int value) const
{
	return (*this > BigInteger(value));
}
bool BigInteger::operator>(const string& value) const
{
	return (*this > BigInteger(value));
}

// '<' 연산자 오버로딩
bool BigInteger::operator<(const BigInteger& value) const
{
	return this->integer < value.integer;
}
bool BigInteger::operator<(int value) const
{
	return (*this < BigInteger(value));
}
bool BigInteger::operator<(const string& value) const
{
	return (*this < BigInteger(value));
}

// '>=' 연산자 오버로딩
bool BigInteger::operator>=(const BigInteger& value) const
{
	return !(*this < value);
}
bool BigInteger::operator>=(int value) const
{
	return !(*this < BigInteger(value));
}
bool BigInteger::operator>=(const string& value) const
{
	return !(*this < BigInteger(value));
}

// '<=' 연산자 오버로딩
bool BigInteger::operator<=(const BigInteger& value) const
{
	return !(*this > value);
}
bool BigInteger::operator<=(int value) const
{
	return !(*this > BigInteger(value));
}
bool BigInteger::operator<=(const string& value) const
{
	return !(*this > BigInteger(value));
}

// '<<' 연산자 오버로딩
ostream& operator<<(ostream& output, const BigInteger& value)
{
	int i;
	for (i = 0; (i < BigInteger::digits) && (value.integer[i] == 0); ++i) {}

	if (i == BigInteger::digits)
	{
		output << 0;
	}
	else
	{
		for (; i < BigInteger::digits; i++)
		{
			output << value.integer[i];
		}
	}

	return output;
}