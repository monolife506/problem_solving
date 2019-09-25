#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> select;

// With next_permutation

void next_p_permutation(int k)
{
	for (size_t i = 0; i < k; i++)
	{
		select.push_back(1);
	}
	for (size_t i = 0; i < vec.size() - k; i++)
	{
		select.push_back(0);
	}
	sort(select.begin(), select.end());

	do
	{
		vector<int> arr;
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (select[i] == 1)
			{
				arr.push_back(vec[i]);
			}
		}

		do
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(arr.begin(), arr.end()));
	} while (next_permutation(select.begin(), select.end()));
}

int main()
{
	vec = { 1, 3, 5, 7, 9 };
	next_p_permutation(2);
}