#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> p(n, -1), q(n, -1);
    vector<pii> px, qx;
    vector<vector<bool>> flag(2, vector<bool>(n + 1, false));
    for (int i = 0; i < n; ++i)
    {
        if (!flag[0][a[i]])
        {
            flag[0][a[i]] = true;
            p[i] = a[i];
            qx.push_back({p[i], i});
        }
        else if (!flag[1][a[i]])
        {
            flag[1][a[i]] = true;
            q[i] = a[i];
            px.push_back({q[i], i});
        }
        else
        {
            cout << "No" << '\n';
            return;
        }
    }

    sort(px.begin(), px.end());
    sort(qx.begin(), qx.end());

    int cur = 1;
    for (int i = 0; i < px.size(); ++i)
    {
        while (cur <= n && flag[0][cur])
            ++cur;

        if (cur > px[i].first)
        {
            cout << "No" << '\n';
            return;
        }

        p[px[i].second] = cur;
        flag[0][cur] = true;
    }

    cur = 1;
    for (int i = 0; i < qx.size(); ++i)
    {
        while (cur <= n && flag[1][cur])
            ++cur;

        if (cur > qx[i].first)
        {
            cout << "No" << '\n';
            return;
        }

        q[qx[i].second] = cur;
        flag[1][cur] = true;
    }

    cout << "Yes" << '\n';

    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";

    cout << '\n';

    for (int i = 0; i < n; ++i)
        cout << q[i] << " ";

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

/*

3
3 2 x
x x 2

*/