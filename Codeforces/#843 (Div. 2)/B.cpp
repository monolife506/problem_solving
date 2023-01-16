#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> p(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        p[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> p[i][j];
            cnt[p[i][j]]++;
        }
    }

    bool ans = false;
    for (int i = 0; i < n; ++i)
    {
        bool flag = true;
        for (int j = 0; j < p[i].size(); ++j)
        {
            if (cnt[p[i][j]] == 1)
                flag = false;
        }

        if (flag)
            ans = true;
    }

    cout << (ans ? "Yes" : "No") << '\n';
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

1 0 0 0 1
0 1 0 1 0
0 1 1 0 0

1 0 0 1
0 1 1 0
0 1 1 1
1 0 0 0

*/