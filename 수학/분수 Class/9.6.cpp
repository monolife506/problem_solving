// 9.6 : Rational Class

#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
	Rational R1;
	Rational R2{ 7, 5 };
	cout << R1 << endl;
	
	cout << "A/B 형식으로 입력 : ";
	cin >> R1;
	cout << R1 << " " << R2 << endl << endl;
	
	cout << R1 + R2 << endl;
	cout << R2 - R1 << " " << R1 - R2 << endl;
	cout << R1 * R2 << " " << R1 / R2 << endl;
	cout << --R1 << " " << --R2 << endl;
	cout << R1 << " " << R2 << endl;
	cout << R1++ << " " << R2++ << endl;
	cout << R1 << " " << R2 << endl;
}
