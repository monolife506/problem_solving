#include <iostream>
#include <vector>

int main()
{
	size_t N, X;
	std::cin >> N >> X;
	std::vector<short> nums(N);
	for (short& num : nums)
		std::cin >> num;
	for (short& num : nums)
	{
		if (num < X)
			std::cout << num << " ";
	}
}
