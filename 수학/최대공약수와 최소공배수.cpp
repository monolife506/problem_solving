// 2609번 : 최대공약수와 최소공배수

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, r);
	}
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	int gcd_num = gcd(num1, num2);
	cout << gcd_num << '\n';
	cout << num1 * num2 / gcd_num;
}