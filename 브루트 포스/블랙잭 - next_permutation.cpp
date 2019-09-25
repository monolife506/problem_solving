// 2798번 : 블랙잭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	vector<int> cards(N);
	for (int& num : cards)
	{
		cin >> num;
	}

	int tmp; int max{ 0 };
	vector<int> choice;
	for (size_t i = 0; i < 3; i++)
	{
		choice.push_back(1);
	}
	for (size_t i = 0; i < cards.size() - 3; i++)
	{
		choice.push_back(0);
	}
	sort(choice.begin(), choice.end());

	do
	{
		tmp = 0;
		for (size_t i = 0; i < cards.size(); i++)
		{
			if (choice[i] == 1)
			{
				tmp += cards[i];
			}
		}
		if (tmp <= M && max < tmp)
		{
			max = tmp;
		}
	} while (next_permutation(choice.begin(), choice.end()));

	cout << max;
}