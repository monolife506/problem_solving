// 11053번: 가장 긴 증가하는 부분 수열
// 14002번: 가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	size_t N;
	size_t max_cnt = 1;
	size_t max_i = 0;
	cin >> N;

	stack<int> LIS;
	vector<int> nums(N);
	vector<int> cnt(N, 1);
	vector<int> last(N, -1);

	for (int &item : nums)
		cin >> item;

	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			if (cnt[j] < cnt[i] + 1 && nums[i] < nums[j])
			{
				cnt[j] = cnt[i] + 1;
				last[j] = i;
				if (max_cnt < cnt[j])
				{
					max_cnt = cnt[j];
					max_i = j;
				}
			}
		}
	}

	cout << max_cnt << '\n';
	while (max_cnt > 0 && max_i != -1)
	{
		(N == 1) ? LIS.push(nums[0]) : LIS.push(nums[max_i]);
		max_i = last[max_i];
		max_cnt--;
	}

	while (!LIS.empty())
	{
		cout << LIS.top() << " ";
		LIS.pop();
	}
}
