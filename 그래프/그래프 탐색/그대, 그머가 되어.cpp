#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1001];
int dist[1001];

int bfs(int a, int b)
{
    queue<int> q;
    q.push(a);

    memset(dist, -1, sizeof(dist));
    dist[a] = 0;

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

    return dist[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, N, M;
    cin >> a >> b >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << bfs(a, b) << '\n';
}