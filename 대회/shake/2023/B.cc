#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    if (k > n / 2)
        k = n - k;

    int gcd_val = gcd(n, k);
    n /= gcd_val;
    k /= gcd_val;

    cout << n * (k - 1) << '\n';
}