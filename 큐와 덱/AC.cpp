// 5430¹ø : AC

#include <iostream>
#include <string>
#include <deque>
#include <cctype>
using namespace std;

int main()
{
	deque<int> D;
	size_t T; cin >> T;

	int num{ 0 }, N;
	string prompt, deque_str;
	bool isReversed{ false }, isError{ false }, isFirstDigit{ false };
	for (size_t testcase = 0; testcase < T; testcase++)
	{
		isReversed = false;
		isError = false;
		isFirstDigit = true;

		cin >> prompt >> N >> deque_str;
		for (size_t i = 1; i < deque_str.size(); i++)
		{
			if (isdigit(deque_str[i]))
			{
				if (isFirstDigit)
				{
					num = deque_str[i] - '0';
					isFirstDigit = false;
				}
				else
				{
					num *= 10;
					num += deque_str[i] - '0';
				}
			}
			else
			{
				if (deque_str.size() != 2)
					D.push_back(num);
				isFirstDigit = true;
			}
		}

		for (const char& command : prompt)
		{
			if (command == 'R') isReversed = !isReversed;
			else // command == 'D'
			{
				if (D.empty())
				{
					isError = true;
					break;
				}
				else isReversed ? D.pop_back() : D.pop_front();
			}
		}

		if (isError) cout << "error";
		else
		{
			cout << "[";
			if (isReversed)
			{
				for (size_t i = D.size(); i > 0; i--)
				{
					num = D.back();
					D.pop_back();
					cout << num;
					if (i != 1) cout << ",";
				}
			}
			else
			{
				for (size_t i = D.size(); i > 0; i--)
				{
					num = D.front();
					D.pop_front();
					cout << num;
					if (i != 1) cout << ",";
				}
			}
			cout << "]";
		}
		cout << '\n';
	}
}