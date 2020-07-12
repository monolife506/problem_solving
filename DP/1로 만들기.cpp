// 1463번 : 1로 나누기

#include <iostream>
#include <array>
using namespace std;

array<int, 1'000'001> min_count = {};
void DP(int cur, int count_now)
{
	if (cur == 1)
	{
		return;
	}

	if (cur % 3 == 0)
	{
		if (min_count[cur / 3] > count_now + 1 || min_count[cur / 3] == 0)
		{
			min_count[cur / 3] = count_now + 1;
			DP(cur / 3, count_now + 1);
		}
	}

	if (cur % 2 == 0)
	{
		if (min_count[cur / 2] > count_now + 1 || min_count[cur / 2] == 0)
		{
			min_count[cur / 2] = count_now + 1;
			DP(cur / 2, count_now + 1);
		}
	}

	if (cur > 1)
	{
		if (min_count[cur - 1] > count_now + 1 || min_count[cur - 1] == 0)
		{
			min_count[cur - 1] = count_now + 1;
			DP(cur - 1, count_now + 1);
		}
	}
}

int main()
{
	int N; 
	cin >> N;
	DP(N, 0);

	cout << min_count[1];
}