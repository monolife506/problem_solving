// 10989번 : 수 정렬하기 3
// Counting Sort 구현..?

#include <iostream>
#include <array>
#define MAX_NUMBER 10000
using namespace std;

array<size_t, MAX_NUMBER> counting = {};

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	size_t N; short tmp;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> tmp;
		counting[tmp - 1]++;
	}
	for (size_t j = 1; j <= MAX_NUMBER; j++)
	{
		for (size_t k = 0; k < counting[j - 1]; k++)
		{
			cout << j << '\n';
		}
	}
}