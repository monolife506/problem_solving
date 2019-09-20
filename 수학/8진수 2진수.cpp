// 1212번 : 8진수 2진수

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string octal, binary; short tmp;
	cin >> octal;
	if (octal == "0")
	{
		cout << "0";
		return 0;
	}

	for (int i = octal.length() - 1; i >= 0; i--)
	{
		tmp = octal.at(i) - 48;
		while (tmp != 0)
		{
			binary.push_back((tmp % 2) + 48);
			tmp /= 2;
		}
		if (octal.at(i) - 48 < 4)
			binary.push_back('0');
		if (octal.at(i) - 48 < 2)
			binary.push_back('0');
		if (octal.at(i) - 48 < 1)
			binary.push_back('0');
	}

	bool isFirstOne{ false };
	for (int i = binary.size() - 1; i >= 0; i--)
	{
		if (isFirstOne == false)
		{
			if (binary[i] == '1')
			{
				cout << binary[i];
				isFirstOne = true;
			}
		}
		else
		{
			cout << binary[i];
		}
	}
}