// 1149번 : RGB거리

#include <iostream>
#include <array>
using namespace std;

int main()
{
    size_t N; cin >> N;
    array<array<short, 3>, 1000> houses;
	for (size_t i = 0; i < N; i++)
	{
		cin >> houses[i][0] >> houses[i][1] >> houses[i][2];
	}
}