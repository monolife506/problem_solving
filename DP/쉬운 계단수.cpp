// 10844번 : 쉬운 계단수

#define ONEB 1'000'000'000

#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

array<array<int, 1 + 9>, 1 + 100> store{};
ll DP(size_t N, size_t cur, int cur_num)
{
	if (N == cur)
	{
		return 1;
	}

	if (store[cur][cur_num] == 0)
	{
		if (cur_num == 0)
		{
			store[cur][cur_num] = DP(N, cur + 1, 1) % ONEB;
		}
		else if (cur_num == 9)
		{
			store[cur][cur_num] = DP(N, cur + 1, 8) % ONEB;
		}
		else
		{
			store[cur][cur_num] = (DP(N, cur + 1, cur_num + 1) % ONEB) +
				(DP(N, cur + 1, cur_num - 1) % ONEB);
		}
	}
	
	return store[cur][cur_num] % ONEB;
}

int main()
{
	size_t N;
	cin >> N;

	ll total{ 0 };
	for (size_t i = 1; i <= 9; i++)
	{
		store = {};
		total += DP(N, 1, i);
	}
	cout << total % ONEB;
}