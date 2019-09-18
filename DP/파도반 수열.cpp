// 9461번 : 파도반 수열

#include <iostream>
#include <array>
using namespace std;

int main()
{
	size_t T, N; cin >> T;
	array<unsigned long long int, 4> nums = {1, 1, 1, 2};
	for (size_t i = 0; i < T; i++)
	{
		cin >> N;
		nums[0] = 1; nums[1] = 1;
		nums[2] = 1; nums[3] = 2;
		for (size_t j = 4; j < N; j++)
		{
			nums[j % 4] = nums[(j - 2) % 4] + nums[(j - 3) % 4];
		}
		cout << nums[(N - 1) % 4] << '\n';
	}
}