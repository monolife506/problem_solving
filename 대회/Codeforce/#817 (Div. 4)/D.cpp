#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    vector<ll> v;
    for (int i = 0; i < n; ++i)
    {
        ll l_val = i;
        ll r_val = (n - 1) - i;

        if (s[i] == 'L')
        {
            ans += l_val;
            if (l_val < r_val)
                v.push_back(r_val - l_val);
        }
        else
        {
            ans += r_val;
            if (l_val > r_val)
                v.push_back(l_val - r_val);
        }
    }

    sort(v.begin(), v.end(), greater<ll>());
    for (int k = 1; k <= n; ++k)
    {
        if (k - 1 < v.size())
            ans += v[k - 1];
        cout << ans << " ";
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