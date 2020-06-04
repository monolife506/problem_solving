// 15651¹ø : N°ú M (3)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	size_t N, M;
	cin >> N >> M;
	
	vector<short> nums(M, 1);
	size_t count{ 1 };
	for (size_t i = 0; i < M; i++)
		count *= N;
	for (size_t i = 0; i < count; i++)
	{
		for (const short& num : nums)
			cout << num << " ";

		nums[M - 1]++;
		for (int j = M - 1; j >= 0; j--)
		{
			if (nums[j] >= N + 1 && j != 0)
			{
				nums[j] = 1;
				nums[j - 1]++;
			}
		}
		cout << '\n';
	}
}