#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1'000'000'007;

ll x[3000], two_mod[3001];

void precompute()
{
    two_mod[0] = 1;
    for (int i = 1; i <= 3000; ++i)
        two_mod[i] = (two_mod[i - 1] * 2) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    ll ans = 0;
    for (int i = 0; i + 1 < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int l = lower_bound(x, x + n, x[i] - (x[j] - x[i])) - x;
            int r = lower_bound(x, x + n, x[j] + (x[j] - x[i])) - x;
            ans += two_mod[l + (n - r)];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

/*

1 ~ k - 1

2^1 - 1
2^2 - 1
2^3 - 1
...

2^1 + 2^2 + 2^3 + ... + 2^(k - 1) - (k - 1)
2^k - (k + 1)

1 2 5 7 8 (2)

1 3 5 11 20 (1)
1 3 5 11 15 (2)


*/