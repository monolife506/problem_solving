// 1238번: 파티

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 3000000;

int N, M, X;
int dist[1001];
int goDist[1001];
vector<P> graph[1001];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(dist[start], start));

    bool visited[1001];
    fill(visited, visited + 1001, false);

    while (!pq.empty())
    {
        int cur;
        do
        {
            cur = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[cur]);

        if (visited[cur])
            break;

        visited[cur] = true;
        for (P &p : graph[cur])
        {
            int next = p.first;
            int w = p.second;

            if (dist[next] > dist[cur] + w)
            {
                dist[next] = dist[cur] + w;
                if (!visited[next])
                    pq.push(P(dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    for (size_t i = 0; i < M; i++)
    {
        int U, V, W;
        cin >> U >> V >> W;
        graph[U].push_back(P(V, W));
    }

    for (size_t i = 1; i <= N; i++)
    {
        if (i == X)
            continue;

        fill(dist, dist + 1001, INF);
        dijkstra(i);
        goDist[i] = dist[X];
    }

    int ans = 0;
    fill(dist, dist + 1001, INF);
    dijkstra(X);
    for (size_t i = 1; i <= N; i++)
    {
        if (i == X)
            continue;

        ans = max(ans, goDist[i] + dist[i]);
    }
    cout << ans;
}

// 10000 * 1000