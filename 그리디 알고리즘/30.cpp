#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const int& A, const int& B)
{
	return A > B;
}

int main()
{
	string num_str;
	cin >> num_str;

	size_t total{ 0 };
	bool isThereZero{ false };
	for (size_t i = 0; i < num_str.size(); i++)
	{
		total += num_str[i] - '0';
		if (num_str[i] == '0')
		{
			isThereZero = true;
		}
	}
	sort(num_str.begin(), num_str.end(), cmp);

	if (total % 3 == 0 && isThereZero == true)
	{
		cout << num_str;
	}
	else
	{
		cout << -1;
	}
}