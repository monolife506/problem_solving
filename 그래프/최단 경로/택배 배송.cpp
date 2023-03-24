#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int N, M;
vector<P> graph[50001];

int dijkstra(int S, int D)
{
    vector<int> dist(N + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[S] = 0;
    pq.push({dist[S], S});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d)
            continue;

        for (P &p : graph[cur])
        {
            int nxt = p.first;
            int w = p.second;
            if (dist[nxt] > dist[cur] + w)
            {
                dist[nxt] = dist[cur] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    return dist[D];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    cout << dijkstra(1, N) << '\n';
}