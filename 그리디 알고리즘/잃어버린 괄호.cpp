// 1541번 : 잃어버린 괄호

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	string input_str; cin >> input_str;

	vector<int> inputs; 
	int num{ 0 }; bool isMinus{ false };
	for (size_t i = 0; i < input_str.length(); i++)
	{
		if (isdigit(input_str[i])) // 숫자
		{
			num *= 10;
			num += input_str[i] - '0';
			if (i == input_str.length() - 1) // 마지막 숫자
				isMinus ? inputs.push_back(-num) : inputs.push_back(num);
		}
		else if (input_str[i] == '-') // '-'
		{
			isMinus ? inputs.push_back(-num) : inputs.push_back(num);
			isMinus = true; num = 0;
		}
		else // '+'
		{
			isMinus ? inputs.push_back(-num) : inputs.push_back(num);
			isMinus = false; num = 0;
		}
	}

	int sum{ 0 }; isMinus = false;
	for (size_t i = 0; i < inputs.size(); i++)
	{
		if (inputs[i] < 0)
		{
			sum += inputs[i];
			if (!isMinus)
				isMinus = true;
		}
		else if (isMinus)
		{
			sum -= inputs[i];
		}
		else
		{
			sum += inputs[i];
		}
	}
	cout << sum;
}