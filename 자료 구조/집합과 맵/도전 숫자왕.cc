#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    int n;
    cin >> n;

    ll m = 0;
    vector<ll> v(n);
    for (ll &vi : v)
    {
        cin >> vi;
        m += vi;
    }

    set<ll> s;
    for (int i = 1; i < (1 << n); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((i & (1 << j)) != 0)
                sum += v[j];
        }

        if (sum <= m)
            s.insert(sum);
    }

    cout << m - s.size() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}

/*

2^10 ~ 1000
2^20 ~ 1000000

2^20 - 1 * n ~ 2000000


*/