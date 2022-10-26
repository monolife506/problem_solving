#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int cnt = 0;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i + 1] < a[i])
        {
            v[a[i] - a[i + 1]].push_back(i + 2);
            ++cnt;
        }
    }

    for (int i = 0; i < n - cnt; ++i)
        cout << 1 << " ";

    for (int i = 1; i < n; ++i)
    {
        for (int j : v[i])
        {
            cout << j << " ";
        }
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

/*

1 1 1
2 -1 2 1
1 -2

4 3 2 1 5
-1 -1 -1 4

5 4 3 2 1
-1 -1 -1 -1

*/