#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] != '0')
                break;

            cnt++;
        }

        ans += s.length() - cnt;
        v.push_back(cnt);
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 1; i < v.size(); i += 2)
        ans += v[i];

    cout << ((ans > m) ? "Sasha" : "Anna") << '\n';
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

a 4 b 3



*/