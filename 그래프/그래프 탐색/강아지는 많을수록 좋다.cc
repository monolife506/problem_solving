#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, a, b;
int dist[100001];
int l[100], r[100];

void bfs()
{
    queue<int> q;
    memset(dist, -1, sizeof(dist));

    q.push(0);
    dist[0] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur + a <= n && dist[cur + a] == -1)
        {
            for (int i = 0; i < m; ++i)
            {
                if (l[i] <= cur + a && cur + a <= r[i])
                    break;
                if (i == m - 1)
                {
                    dist[cur + a] = dist[cur] + 1;
                    q.push(cur + a);
                }
            }
        }

        if (cur + b <= n && dist[cur + b] == -1)
        {
            for (int i = 0; i < m; ++i)
            {
                if (l[i] <= cur + b && cur + b <= r[i])
                    break;
                if (i == m - 1)
                {
                    dist[cur + b] = dist[cur] + 1;
                    q.push(cur + b);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> a >> b;

    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i];

    bfs();

    cout << dist[n] << endl;
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