#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int p[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    ll k;
    cin >> k;

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (ll j = p[i]; j <= k; j *= p[i])
            ans += k / j;
    }

    cout << ans << '\n';
}

/*

2 4 6 8 ..

50
25
12
6
3
1

-> 97

33
11
3
1

*/