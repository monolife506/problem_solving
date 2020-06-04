// 11051번 : 이항 계수 2

#include <iostream>
using namespace std;

typedef unsigned long long ll;
ll tmp[1001][1001] = {};

ll C(ll n, ll k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (n == k)
	{
		return 1;
	}
	else
	{
		if (tmp[n][k] == 0)
		{
			tmp[n][k] = C(n - 1, k - 1) + C(n - 1, k);
		}
		return tmp[n][k] % 10007;
	}
}

int main()
{
	ll N, K;
	cin >> N >> K;
	cout << C(N, K) % 10007;
}
