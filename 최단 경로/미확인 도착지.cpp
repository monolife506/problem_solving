// 9370번: 미확인 도착지

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int INF = INT32_MAX;
typedef pair<int, int> P;

void dijkstra(int start, const vector<vector<P>> &graph, vector<int> &dist)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> visited(graph.size() + 1, false);

    dist[start] = 0;
    pq.push(P(0, start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        visited[cur] = true;
        pq.pop();

        for (auto &p : graph[cur])
        {
            int nxt = p.first;
            int d = p.second;
            if (dist[cur] + d < dist[nxt])
            {
                dist[nxt] = dist[cur] + d;
                if (!visited[nxt])
                    pq.push(P(dist[nxt], nxt));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m, t;
        int s, g, h;
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        vector<vector<P>> graph(n + 1);
        vector<int> distS(n + 1, INF);
        vector<int> distG(n + 1, INF);
        vector<int> distH(n + 1, INF);
        vector<int> candidate(t);

        for (int j = 0; j < m; j++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back(P(b, d));
            graph[b].push_back(P(a, d));
        }
        for (int &x : candidate)
            cin >> x;

        dijkstra(s, graph, distS);
        dijkstra(g, graph, distG);
        dijkstra(h, graph, distH);
        sort(candidate.begin(), candidate.end());

        for (int &x : candidate)
        {
            if (distS[x] == INF)
                continue;

            // S-G-H-X
            if (distS[g] != INF && distH[x] != INF)
            {
                if (distS[g] + distG[h] + distH[x] == distS[x])
                {
                    cout << x << " ";
                    continue;
                }
            }

            // S-H-G-X
            if (distS[h] != INF && distG[x] != INF)
            {
                if (distS[h] + distH[g] + distG[x] == distS[x])
                {
                    cout << x << " ";
                    continue;
                }
            }
        }

        cout << "\n";
    }
}