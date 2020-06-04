// 2010번 문제 : 플러그

#include <iostream>
#include <array>
using namespace std;

array<short, 500000 - 1> multitap = {};

int main()
{
	size_t N, total{ 1 }; cin >> N;
	for (size_t i = 0; i < N; i++)
		cin >> multitap[i];
	for (size_t j = 0; j < N; j++)
	{
		if (multitap[j] == 0)
			break;
		else
			total += (multitap[j] - 1);
	}
	cout << total << endl;
}