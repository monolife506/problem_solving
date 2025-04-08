#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> psum_a(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i)
    {
        psum_a[i] = psum_a[i - 1];
        psum_a[i][a[i - 1] - 'a']++;
    }

    vector<vector<int>> psum_b(m + 1, vector<int>(26, 0));
    for (int i = 1; i <= m; ++i)
    {
        psum_b[i] = psum_b[i - 1];
        psum_b[i][b[i - 1] - 'a']++;
    }

    for (int i = min(n, m); i > 0; --i)
    {
        set<vector<int>> s;
        for (int j = 0; i + j <= n; ++j)
        {
            vector<int> cnt(26, 0);
            for (int k = 0; k < 26; ++k)
                cnt[k] = psum_a[i + j][k] - psum_a[j][k];

            s.insert(cnt);
        }

        for (int j = 0; i + j <= m; ++j)
        {
            vector<int> cnt(26, 0);
            for (int k = 0; k < 26; ++k)
                cnt[k] = psum_b[i + j][k] - psum_b[j][k];

            if (s.find(cnt) != s.end())
            {
                cout << i << endl;
                return;
            }
        }
    }

    cout << 0 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}