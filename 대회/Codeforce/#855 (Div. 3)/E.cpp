#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
string s, t;
bool visited[200000];

void dfs(int cur)
{
    visited[cur] = true;
    if (cur - k >= 0 && !visited[cur - k])
        dfs(cur - k);
    if (cur + k < n && !visited[cur + k])
        dfs(cur + k);
    if (cur - (k + 1) >= 0 && !visited[cur - (k + 1)])
        dfs(cur - (k + 1));
    if (cur + (k + 1) < n && !visited[cur + (k + 1)])
        dfs(cur + (k + 1));
}

void solve()
{
    cin >> n >> k >> s >> t;

    fill_n(&visited[0], n, false);
    if (k < n)
        dfs(0);

    int cnt[2][26] = {};
    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
        {
            cnt[0][s[i] - 'a']++;
            cnt[1][t[i] - 'a']++;
        }
        else if (s[i] != t[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[0][i] != cnt[1][i])
        {
            cout << "NO" << '\n';
            return;
        }
    }

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

n = 7

k = 5
(1 6) (2 7) (1 7)

k = 4
(1 5) (2 6) (3 7) (1 6) (2 7)

*/