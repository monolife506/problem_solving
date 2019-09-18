// 2798¹ø : ºí·¢Àè

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, sum, max_sum = 0;
	cin >> N >> M;
	vector<int> cards(N);
	for (int& item : cards)
	{
		cin >> item;
	}
	for (size_t i = 0; i < N - 2; i++)
	{
		for (size_t j = i + 1; j < N - 1; j++)
		{
			for (size_t k = j + 1; k < N; k++)
			{
				sum = cards[i] + cards[j] + cards[k];
				if (sum > M)
				{
					continue;
				}
				else
				{
					if (sum >= max_sum)
					{
						max_sum = sum;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	cout << max_sum << endl;
}
