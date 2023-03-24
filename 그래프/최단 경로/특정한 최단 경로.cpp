// 1504번: 특정한 최단 경로

#include <iostream>
#include <queue>
#include <array>
#include <vector>
using namespace std;

const int MAX_N = 801;
typedef pair<int, int> P;

array<vector<P>, MAX_N> graph;
array<array<int, MAX_N>, 3> di; // 1/v1/v2부터의 최단거리
array<int, 3> st;               // 1/v1/v2

void dijkstra(int start, array<int, MAX_N> &dist)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    array<bool, MAX_N> visited = {};
    pq.push(P(0, start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        visited[cur] = true;
        pq.pop();

        for (auto &p : graph[cur])
        {
            int nxt = p.first;
            int w = p.second;

            if (dist[cur] + w < dist[nxt] || dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + w;
                if (!visited[nxt])
                    pq.push(P(dist[nxt], nxt));
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    for (size_t i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(P(b, c));
        graph[b].push_back(P(a, c));
    }

    st[0] = 1;
    cin >> st[1] >> st[2];
    for (size_t i = 0; i < 3; i++)
    {
        di[i].fill(-1);
        di[i][st[i]] = 0;
        dijkstra(st[i], di[i]);
    }

    bool flag1 = (di[0][st[1]] != -1 && di[1][st[2]] != -1 && di[2][N] != -1); // 1 => v1 => v2 => N
    bool flag2 = (di[0][st[2]] != -1 && di[2][st[1]] != -1 && di[1][N] != -1); // 1 => v2 => v1 => N
    int dist1 = di[0][st[1]] + di[1][st[2]] + di[2][N];
    int dist2 = di[0][st[2]] + di[2][st[1]] + di[1][N];

    if (flag1 && flag2)
        cout << min(dist1, dist2);
    else if (flag1)
        cout << dist1;
    else if (flag2)
        cout << dist2;
    else
        cout << -1;
}