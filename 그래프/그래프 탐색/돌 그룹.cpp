#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dist[501][501][501];

int bfs(int a, int b, int c)
{
    queue<pair<int, pii>> q;
    q.push({a, {b, c}});
    dist[a][b][c] = 0;

    while (!q.empty())
    {
        int cur_a = q.front().first;
        int cur_b = q.front().second.first;
        int cur_c = q.front().second.second;
        q.pop();

        if (cur_a != cur_b)
        {
            if (cur_a > cur_b &&)
            {
            }
            else
            {
            }
        }

        if (cur_b != cur_c)
        {
        }

        if (cur_c != cur_a)
        {
        }
    }
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
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