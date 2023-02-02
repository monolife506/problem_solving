#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    map<char, int> idx;
    for (char c : a)
    {
        if (idx.find(c) == idx.end())
            idx[c] = idx.size();
    }

    ll ans = 0;
    for (int i = 0; i < (1 << idx.size()); ++i)
    {
        if (__builtin_popcount(i) > k)
            continue;

        string s = a;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << idx[s[j]]))
                s[j] = b[j];
        }

        ll tmp = 0;

        int l = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((j == 0 || s[j - 1] != b[j - 1]) && s[j] == b[j])
                l = j;
            if (s[j] == b[j] && (j == n - 1 || s[j + 1] != b[j + 1]))
                tmp += (1LL * (j - l + 1) * (j - l) / 2) + (j - l + 1);
        }

        ans = max(ans, tmp);
    }

    cout << ans << '\n';
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