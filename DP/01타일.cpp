// 1904번 : 01타일

#include <iostream>
#include <array>
using namespace std;

int main()
{
	size_t N; cin >> N;
	array<unsigned long long, 2> nums = { 1, 1 };
	for (size_t i = 0; i < N; i++)
	{
		nums[i % 2] += (nums[(i + 1) % 2] % 15746);
		nums[i % 2] %= 15746;
	}
	cout << nums[N % 2];
}