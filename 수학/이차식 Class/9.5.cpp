// 9.5 : Quadratic Equations Class

#include <iostream>
#include <string>
#include <stdexcept>
#include "Quadratic.h"
using namespace std;

void try_solve(Quadratic& Q, char c)
{
	if (c == '+')
	{
		cout << Q.toString() << " 의 큰 해" << endl;
	}
	else if (c == '-')
	{
		cout << Q.toString() << " 의 작은 해" << endl;
	}

	try
	{
		cout << Q.solve(c) << endl;
	}
	catch (invalid_argument& e)
	{
		cout << "Exception occured : " << e.what() << "\n";
	}
}

int main()
{
	Quadratic q1{ 1, 4, 4 };
	Quadratic q2{ 1, 1, 8 };
	Quadratic q3{ 1, -5, 4 };
	char tmp; cin >> tmp;

	try_solve(q1, tmp);
	try_solve(q2, tmp);
	try_solve(q3, tmp);

	Quadratic q4{ 1, 5, -5 };
	Quadratic q5{ 2, 4, 5 };
	Quadratic q6 = q4 + q5;
	Quadratic q7 = q5 - q4;

	try_solve(q6, tmp);
	try_solve(q7, tmp);
}