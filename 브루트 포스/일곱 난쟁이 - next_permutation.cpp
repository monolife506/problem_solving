// 2039¹ø : ÀÏ°ö ³­ÀïÀÌ
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	array<short, 9> minions;
	size_t total{ 0 };

	for (size_t i = 0; i < 9; i++)
	{
		cin >> minions[i];
		total += minions[i];
	}
	sort(minions.begin(), minions.end());

	do
	{
		if (total - (minions[0] + minions[1]) == 100)
			break;
	} while (next_permutation(minions.begin(), minions.end()));

	for (size_t i = 2; i < 9; i++)
	{
		cout << minions[i] << '\n';
	}
}