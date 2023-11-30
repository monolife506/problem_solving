#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    string s;
    cin >> s;

    vector<pii> candidates;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
        {
            if (a[i] <= n)
                candidates.push_back({max(1, a[i]), n});
        }
        else
        {
            if (a[i] >= 1)
                candidates.push_back({1, min(n, a[i])});
        }
    }

    if (candidates.size() != n)
    {
        cout << "NO" << '\n';
        return;
    }

    sort(candidates.begin(), candidates.end());
    for (int i = 1; i <= n; ++i)
    {
        int l = candidates[i - 1].first;
        int r = candidates[i - 1].second;
        if (i < l || r < i)
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

/*

red +1
blue -1

2
1 -2
BR

        1
-2 -1 0 1 2


*/