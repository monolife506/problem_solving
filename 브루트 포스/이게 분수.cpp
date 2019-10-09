#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<double, 4> nums;
	for (double& item : nums)
	{
		cin >> item;
	}
	
	double max{(nums[0] / nums[2]) + (nums[1] / nums[3])}, tmp;
	size_t count{ 0 };
	for (size_t i = 0; i < 3; i++)
	{
		tmp = nums[2]; 
		nums[2] = nums[3]; nums[3] = nums[1];
		nums[1] = nums[0]; nums[0] = tmp;
		tmp = (nums[0] / nums[2]) + (nums[1] / nums[3]);
		if (tmp > max)
		{
			max = tmp;
			count = i + 1;
		}
	}

	cout << count;
}

// 0 -> 1
// 1 -> 3
// 2 -> 0
// 3 -> 2