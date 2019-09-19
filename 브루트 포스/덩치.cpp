//  7568번 : 덩치

#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	size_t N, count; cin >> N;
	vector<array<int, 2>> people(N);
	for (auto& arr : people)
	{
		cin >> arr[0] >> arr[1];
	}
	for (size_t i = 0; i < N; i++)
	{
		count = 1;
		for (size_t j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				if (people[i][0] < people[j][0] && people[i][1] < people[j][1])
				{
					count++;
				}
			}
		}
		cout << count << " ";
	}
}