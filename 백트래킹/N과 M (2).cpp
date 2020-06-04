// 15650¹ø : N°ú M (2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	short N, M;
	cin >> N >> M;

	vector<short> nums(N);
	for (size_t i = 0; i < N; i++)
		nums[i] = i + 1;
	vector<bool> selected(N, 0);
	for (size_t i = 0; i < M; i++)
		selected[i] = 1;

	do
	{
		for (size_t i = 0; i < N; i++)
		{
			if (selected[i])
				cout << nums[i] << " ";
		}
		cout << '\n';
	} while (prev_permutation(selected.begin(), selected.end()));
}