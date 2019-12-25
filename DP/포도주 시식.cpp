// 2156번 : 포도주 시식

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 1 + 10000> wine;
array<array<int, 2>, 1 + 10000> memo{};

// 재귀 풀이 (시간 초과)
/*
void DP(size_t N, size_t cur, int sum, int cnt)
{
	if (cur + 1 > N) return;
	if (cnt != 1 && memo[cur + 1][cnt + 1] <= sum + wine[cur + 1])
	{
		memo[cur + 1][cnt + 1] = sum + wine[cur + 1];
		DP(N, cur + 1, sum + wine[cur + 1], cnt + 1);
	}
	for (size_t i = 2; i <= 3; i++)
	{
		if (cur + i > N) return;
		if (memo[cur + i][0] <= sum + wine[cur + i])
		{
			memo[cur + i][0] = sum + wine[cur + i];
			DP(N, cur + i, sum + wine[cur + i], 0);
		}
	}
}
*/

int main()
{
	size_t N; cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		cin >> wine[i];
	}

	// 반복 풀이
	memo[1][0] = wine[1];
	memo[2][0] = wine[2];
	memo[2][1] = wine[1] + wine[2];
	for (size_t i = 3; i <= N; i++)
	{
		memo[i][0] = max(max(memo[i - 2][0], memo[i - 2][1]),
			max(memo[i - 3][0], memo[i - 3][1])) + wine[i];
		memo[i][1] = memo[i - 1][0] + wine[i];
	}
	cout << max(max(memo[N - 1][0], memo[N - 1][1]),
		max(memo[N][0], memo[N][1]));
}