#include <iostream>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int team{ 0 };
	while (N + M - 3 >= K && N - 2 >= 0 && M - 1 >= 0)
	{
		N -= 2;
		M -= 1;
		team++;
	}
	cout << team;
}