#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n % 2 == 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<pair<int, int>> p;
        for (int i = 2; i <= n; i += 2)
        {
            if (a[i] == a[i - 1])
            {
                p.push_back({i - 1, i});
            }
            else
            {
                p.push_back({i - 1, i - 1});
                p.push_back({i, i});
            }
        }

        cout << p.size() << '\n';
        for (int i = 0; i < p.size(); ++i)
            cout << p[i].first << " " << p[i].second << '\n';
    }
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


1 1 -1 1

*/