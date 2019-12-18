// 2004번 : 조합 0의 개수

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll five_count(ll n)
{
	ll count{ 0 };
	for (ll i = 5; n / i >= 1; i *= 5)
	{
		count += n / i;
	}
	return count;
}

ll two_count(ll n)
{
	ll count{ 0 };
	for (ll i = 2; n / i >= 1; i *= 2)
	{
		count += n / i;
	}
	return count;
}

int main()
{
	ll N, M;
	cin >> N >> M;

	ll two_total = two_count(N) - two_count(N - M) - two_count(M);
	ll five_total = five_count(N) - five_count(N - M) - five_count(M);
	cout << min(two_total, five_total);
}