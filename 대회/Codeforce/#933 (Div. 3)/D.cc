#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;

    set<int> s;
    s.insert(x - 1);
    for (int i = 0; i < m; ++i)
    {
        int r;
        char c;
        cin >> r >> c;

        vector<int> v;
        for (auto &num : s)
            v.push_back(num);

        s.clear();

        if (c == '0')
        {
            for (auto &vi : v)
                s.insert((vi + r) % n);
        }
        else if (c == '1')
        {
            for (auto &vi : v)
                s.insert((vi - r + n) % n);
        }
        else // c == '?'
        {
            for (auto &vi : v)
            {
                s.insert((vi + r) % n);
                s.insert((vi - r + n) % n);
            }
        }
    }

    cout << s.size() << '\n';
    for (auto &num : s)
        cout << num + 1 << ' ';

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