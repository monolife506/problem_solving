// 2579번 : 계단 오르기

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<array<int, 2>> maxnum;

void DP(int stairsCount, int sum, int cur, size_t stairSize)
{
	if (stairsCount == 2)
	{
		if (cur + 2 >= stairSize) return;
		if (sum + nums[cur + 2] > maxnum[cur + 2][1])
		{
			maxnum[cur + 2][1] = sum + nums[cur + 2];
			DP(1, maxnum[cur + 2][1], cur + 2, stairSize);
		}
	}
	else
	{
		if (cur + 1 >= stairSize) return;
		if (sum + nums[cur + 1] > maxnum[cur + 1][0])
		{
			maxnum[cur + 1][0] = sum + nums[cur + 1];
			DP(++stairsCount, maxnum[cur + 1][0], cur + 1, stairSize);
		}

		if (cur + 2 >= stairSize) return;
		if (sum + nums[cur + 2] > maxnum[cur + 2][1])
		{
			maxnum[cur + 2][1] = sum + nums[cur + 2];
			DP(1, maxnum[cur + 2][1], cur + 2, stairSize);
		}
	}
}

int main()
{
	size_t N;
	cin >> N;

	int num;
	for (size_t i = 0; i < N; i++)
	{
		cin >> num;
		nums.push_back(num);
	}
	for (size_t i = 0; i < N; i++)
	{
		maxnum.push_back({ 0, 0 });
	}

	DP(0, 0, -1, N);
	cout << max(maxnum[N - 1][0], maxnum[N - 1][1]);
}