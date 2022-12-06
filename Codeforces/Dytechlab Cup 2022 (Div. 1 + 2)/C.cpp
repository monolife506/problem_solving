#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, x, y;
    pii p[3];

    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> p[i].first >> p[i].second;
    cin >> x >> y;

    sort(p, p + 3);

    bool flag[2][2] = {};
    if (p[1].first == p[0].first && p[1].second == p[2].second)
    {
        flag[0][p[1].first % 2] = true;
        flag[1][p[1].second % 2] = true;
    }
    else if (p[1].second == p[0].second && p[1].first == p[2].first)
    {
        flag[0][p[1].first % 2] = true;
        flag[1][p[1].second % 2] = true;
    }
    else if (p[2].first == p[1].first && p[2].second == p[0].second)
    {
        flag[0][p[2].first % 2] = true;
        flag[1][p[2].second % 2] = true;
    }
    else
    {
        flag[0][p[0].first % 2] = true;
        flag[1][p[0].second % 2] = true;
    }

    if (!flag[0][x % 2] && !flag[1][y % 2])
        cout << "NO" << '\n';
    else if (p[0] == pii(1, 1) && p[1] == pii(1, 2) && p[2] == pii(2, 1) && x != 1 && y != 1)
        cout << "NO" << '\n';
    else if (p[0] == pii(n - 1, 1) && p[1] == pii(n, 1) && p[2] == pii(n, 2) && x != n && y != 1)
        cout << "NO" << '\n';
    else if (p[0] == pii(1, n - 1) && p[1] == pii(1, n) && p[2] == pii(2, n) && x != 1 && y != n)
        cout << "NO" << '\n';
    else if (p[0] == pii(n - 1, n) && p[1] == pii(n, n - 1) && p[2] == pii(n, n) && x != n && y != n)
        cout << "NO" << '\n';
    else
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




*/