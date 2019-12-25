// 11053번: 가장 긴 증가하는 부분 수열

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 1000> nums;
array<int, 1000> cnt;

int main()
{
	size_t N; cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			if (cnt[j] < cnt[i] + 1 && nums[i] < nums[j])
			{
				cnt[j] = cnt[i] + 1;
			}
		}
	}
	cout << *(max_element(cnt.begin(), cnt.end())) + 1;
}
