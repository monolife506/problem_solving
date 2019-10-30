// 2748번 : 피보나치 수 2

#include <iostream>
using namespace std;

unsigned long long arr[91] = {};

unsigned long long DP(int N)
{
	if (arr[N] != 0)
		return arr[N];
	else if (N == 0)
		return 0;
	else if (N == 1)
		return 1;
	else
	{
		arr[N] = DP(N - 1) + DP(N - 2);
		return arr[N];
	}
}

int main()
{
	int N; cin >> N;
	cout << DP(N);
}

