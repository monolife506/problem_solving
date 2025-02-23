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

    vector<int> x(n);
    set<int> s;
    for (int &xi : x)
    {
        cin >> xi;
        s.insert(xi);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((x[i] + x[j]) % 2 != 0)
                continue;
            if (s.find((x[i] + x[j]) / 2) != s.end())
                ans++;
        }
    }

    cout << ans << endl;
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

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}