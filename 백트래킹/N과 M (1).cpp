// 15649¹ø : N°ú M (1)

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	short N, M;
	cin >> N >> M;

	vector<short> nums(N);
	array<vector<short>, 2> compare;
	for (size_t i = 0; i < 2; i++)
		compare[i] = vector<short>(M, 0);
	for (size_t i = 1; i <= N; i++)
		nums[i - 1] = i;

	do
	{
		for (size_t i = 0; i < M; i++)
		{
			compare[0][i] = nums[i];
		}
		if (compare[0] != compare[1])
		{
			for (size_t i = 0; i < M; i++)
				cout << compare[0][i] << " ";
			cout << '\n';
		}
		compare[1] = compare[0];
	} while (next_permutation(nums.begin(), nums.end()));
}