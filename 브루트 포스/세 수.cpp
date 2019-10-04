#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int, 3> nums;
	for (int& item : nums)
	{
		cin >> item;
	}

	if (nums[0] + nums[1] == nums[2])
	{
		cout << nums[0] << '+' << nums[1] << '=' << nums[2];
		return 0;
	}
	if (nums[0] - nums[1] == nums[2])
	{
		cout << nums[0] << '-' << nums[1] << '=' << nums[2];
		return 0;
	}
	if (nums[0] * nums[1] == nums[2])
	{
		cout << nums[0] << '*' << nums[1] << '=' << nums[2];
		return 0;
	}
	if (nums[0] / nums[1] == nums[2])
	{
		cout << nums[0] << '/' << nums[1] << '=' << nums[2];
		return 0;
	}
	if (nums[0] == nums[1] + nums[2])
	{
		cout << nums[0] << '=' << nums[1] << '+' << nums[2];
		return 0;
	}
	if (nums[0] == nums[1] - nums[2])
	{
		cout << nums[0] << '=' << nums[1] << '-' << nums[2];
		return 0;
	}
	if (nums[0] == nums[1] * nums[2])
	{
		cout << nums[0] << '=' << nums[1] << '*' << nums[2];
		return 0;
	}
	if (nums[0] == nums[1] / nums[2])
	{
		cout << nums[0] << '=' << nums[1] << '/' << nums[2];
		return 0;
	}
}