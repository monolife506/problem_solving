#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<vector<string>> v(3, vector<string>(n));
    map<string, int> m;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
            if (m.find(v[i][j]) == m.end())
                m[v[i][j]] = 1;
            else
                m[v[i][j]]++;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        int score = 0;
        for (int j = 0; j < n; ++j)
        {
            if (m[v[i][j]] == 1)
                score += 3;
            else if (m[v[i][j]] == 2)
                score += 1;
        }

        cout << score << " ";
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