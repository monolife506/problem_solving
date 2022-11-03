#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), idx;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] != 0)
            idx.push_back(i);
    }

    if (idx.size() % 2 == 1)
    {
        cout << -1 << '\n';
    }
    else if (idx.size() == 0)
    {
        cout << 1 << '\n';
        cout << 1 << " " << n << '\n';
    }
    else
    {
        vector<pair<int, int>> p;

        if (idx.front() > 1)
            p.push_back({1, idx.front() - 1});

        for (int i = 1; i < idx.size(); i += 2)
        {
            if (a[idx[i]] == a[idx[i - 1]])
            {
                if (idx[i] == idx[i - 1] + 1)
                {
                    p.push_back({idx[i - 1], idx[i]});
                }
                else
                {
                    p.push_back({idx[i - 1], idx[i] - 2});
                    p.push_back({idx[i] - 1, idx[i]});
                }
            }
            else
            {
                p.push_back({idx[i - 1], idx[i - 1]});

                if (idx[i] != idx[i - 1] + 1)
                    p.push_back({idx[i - 1] + 1, idx[i] - 1});

                p.push_back({idx[i], idx[i]});
            }

            if (i + 1 != idx.size() && idx[i] + 1 != idx[i + 1])
                p.push_back({idx[i] + 1, idx[i + 1] - 1});
        }

        if (idx.back() < n)
            p.push_back({idx.back() + 1, n});

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