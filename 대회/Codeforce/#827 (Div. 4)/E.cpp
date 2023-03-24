#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<ll> h(n + 1), min_k(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        min_k[i] = max(min_k[i - 1], h[i]);
        h[i] += h[i - 1];
    }
    for (int i = 0; i < q; ++i)
    {
        int k;
        cin >> k;

        int idx = upper_bound(min_k.begin(), min_k.end(), k) - min_k.begin();
        cout << h[idx - 1] << " ";
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