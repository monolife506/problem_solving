// 9375¹ø : ÆÐ¼Ç¿Õ ½ÅÇØºó

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	size_t T;
	cin >> T;

	int total{ 1 };
	string tmp, kind;

	vector<string> kinds;
	map<string, int> count;

	for (size_t i = 0; i < T; i++)
	{
		size_t N;
		cin >> N;

		kinds.clear();
		count.clear();

		for (size_t i = 0; i < N; i++)
		{
			cin >> tmp >> kind;
			if (find(kinds.begin(), kinds.end(), kind) == kinds.end())
			{
				count[kind] = 1;
				kinds.push_back(kind);
			}
			else
			{
				count[kind]++;
			}
		}

		total = 1;
		for (const string& item : kinds)
		{
			total *= (count[item] + 1);
		}
		cout << total - 1 << '\n';
	}
}