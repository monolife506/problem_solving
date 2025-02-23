#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, dist[300001];
vector<int> graph[300001];

void bfs()
{
    queue<int> q;
    q.push(x);

    memset(dist, -1, sizeof(dist));
    dist[x] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[nxt] == -1)
            {
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    bfs();

    bool flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == k)
        {
            flag = true;
            cout << i << '\n';
        }
    }

    if (!flag)
    {
        cout << -1 << '\n';
    }
}