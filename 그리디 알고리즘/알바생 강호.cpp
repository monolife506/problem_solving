#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int& A, int& B)
{
	return A > B;
}

int main()
{
	size_t N; 
	unsigned long long total{ 0 };
	cin >> N;

	vector<int> tips(N);
	for (int& money : tips)
	{
		cin >> money;
	}
	sort(tips.begin(), tips.end(), cmp);

	int tip;
	for (size_t i = 0; i < N; i++)
	{
		tip = tips[i] - i;
		total += (tip > 0 ? tip : 0);
	}
	cout << total;
}
