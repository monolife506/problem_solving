// 4949¹ø : ±ÕÇüÀâÈù ¼¼»ó

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> S;
	string input_str;

	while (input_str != ".")
	{
		getline(cin, input_str);
		if (input_str == ".") break;

		for (const char& singlechar : input_str)
		{
			if (singlechar == '(' || singlechar == '[') S.push(singlechar);
			else if (singlechar == ')')
			{
				if (S.empty())
				{
					S.push('X');
					break;
				}
				if (S.top() != '(') break;
				else S.pop();
			}
			else if (singlechar == ']')
			{
				if (S.empty())
				{
					S.push('X');
					break;
				}
				if (S.top() != '[') break;
				else S.pop();
			}
		}

		if (S.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';

		while (!S.empty()) S.pop();
	}
}