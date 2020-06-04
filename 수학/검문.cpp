// 2981¹ø : °Ë¹®

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, r);
	}
}

int main()
{
	size_t N;
	cin >> N;

	vector<int> nums(N);
	for (int& num : nums)
	{
		cin >> num;
	}
	sort(nums.begin(), nums.end());

	vector<int> diff_num(N - 1);
	for (size_t i = 0; i < N - 1; i++)
	{
		diff_num[i] = nums[i + 1] - nums[i];
	}
	
	int diff_gcd;
	if (N == 2)
	{
		diff_gcd = diff_num[0];
	}
	else
	{
		diff_gcd = gcd(diff_num[0], diff_num[1]);
		for (size_t i = 2; i < N - 1; i++)
		{
			diff_gcd = gcd(diff_gcd, diff_num[i]);
		}
	}

	nums.clear();
	for (size_t i = 1; i <= sqrt(diff_gcd); i++)
	{
		if (diff_gcd % i == 0)
		{
			if (i != 1 && i != sqrt(diff_gcd))
			{
				cout << i << " ";
			}
			nums.push_back(i);
		}
	}
	for (int i = nums.size() - 1; i >= 0 ; i--)
	{
		cout << diff_gcd / nums[i] << " ";
	}
}
