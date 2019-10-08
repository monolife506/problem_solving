// 9.14 && 10.9: Big Integer Class
// 단점 : 큰 수의 곱셈과 나눗셈 시 속도가 기하급수적으로 느려짐
// 알고 있는 범위에서 해결할 방법이 있는가?

#include <iostream>
#include <string>
#include "BigInteger.h"
using namespace std;

int main()
{
	BigInteger A{ "9999999999999999999999999" };
	A = A + 1;
	cout << boolalpha << A << endl;

	BigInteger B{ "10000000000000000000000000000000000" };
	BigInteger B2{ "442" };
	BigInteger B3{ "530" };
	BigInteger B4{ 531 };
	B = B - 1;
	B2 = B2 - 92;
	cout << B << endl;
	cout << B2 << endl;
	cout << B2 + B3 << endl;
	cout << B3 - B2 << endl;

	BigInteger C{ "100000000000000000000000000000000000000" };
	BigInteger D{ 99 };
	BigInteger E{ 100 };
	BigInteger F{ "100000000000000000000" };
	BigInteger G{ "100000000000000000000" };
	BigInteger H{ 1030009 };
	BigInteger I{ 1030009 };
	cout << (F == G) << endl;
	cout << (F == A) << endl;
	cout << (F > G) << endl;
	cout << (F < G) << endl;
	cout << (F < A) << endl;
	cout << (D > A) << endl;
	cout << (D > E) << endl;
	cout << (D < E) << endl;

	cout << C * D << endl;
	cout << H * I << endl;
	cout << D / E << endl;
	cout << B4 / B3 << endl;
	cout << F / G << endl;
	cout << H / E << endl;
	cout << C / D << endl;
}