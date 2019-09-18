// 1712번 : 손익분기점

#include <iostream>
using namespace std;

int main()
{
	unsigned int A, B, C;
	cin >> A >> B >> C;
	if (B >= C)
		cout << -1;
	else
		cout << (A / (C - B)) + 1;
}