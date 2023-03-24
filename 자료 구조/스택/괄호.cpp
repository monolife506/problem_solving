// 9012번: 괄호

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	size_t T;
	cin >> T;

	stack<char> S;
	string input_str;
	char now;
	int p_count;

	for (size_t i = 0; i < T; i++)
	{
		p_count = 0;
		cin >> input_str;
		for (size_t j = 0; j < input_str.size(); j++)
			S.push(input_str[j]);

		while (!S.empty())
		{
			now = S.top();
			S.pop();
			if (now == ')')
				++p_count;
			else if (now == '(')
			{
				--p_count;
				if (p_count < 0)
					break;
			}
		}
		while (!S.empty())
			S.pop();

		if (p_count == 0)
			cout << "YES"s;
		else
			cout << "NO"s;
		cout << '\n';
	}
}