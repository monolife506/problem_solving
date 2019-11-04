// 1149¹ø : RGB°Å¸®

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
	size_t N; cin >> N;
	vector<array<int, 3>> house(N);
	for (array<int, 3>& item : house)
		cin >> item[0] >> item[1] >> item[2];

	vector<array<int, 3>> house_sum(N, array<int, 3>{1000001, 1000001, 1000001});
	house_sum[0] = house[0];
	for (size_t i = 1; i < N; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				if (j == k) continue;
				else if (house_sum[i][k] > (house_sum[i - 1][j] + house[i][k]))
					house_sum[i][k] = house_sum[i - 1][j] + house[i][k];
			}
		}
	}

	int lowest{house_sum[N - 1][0]};
	for (size_t i = 1; i < 3; i++)
	{
		if (lowest > house_sum[N - 1][i])
			lowest = house_sum[N - 1][i];
	}
	cout << lowest;
}