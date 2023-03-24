#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + b[i];

    vector<ll> imos(n + 1, 0), remain(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int idx = upper_bound(psum.begin(), psum.end(), a[i] + psum[i - 1]) - psum.begin();
        if (idx > i)
        {
            imos[i]++;
            if (idx <= n)
                imos[idx]--;
        }

        if (idx <= n)
            remain[idx] += (a[i] + psum[i - 1]) - psum[idx - 1];
    }

    ll val = 0;
    for (int i = 1; i <= n; ++i)
    {
        val += imos[i];
        cout << val * b[i] + remain[i] << " ";
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}