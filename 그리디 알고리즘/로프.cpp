// 2217¹ø : ·ÎÇÁ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	size_t N; cin >> N;
	vector<int> ropes(N);
	for (int& w : ropes)
	{
		cin >> w;
	}
	
	sort(ropes.begin(), ropes.end(), greater<int>());
	size_t largest = ropes[0];
	for (size_t i = 1; i < N; i++)
	{
		if (largest < ropes[i] * (i + 1))
		{
			largest = ropes[i] * (i + 1);
		}
	}
	cout << largest;
}

