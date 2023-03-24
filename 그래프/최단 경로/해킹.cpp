#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
typedef pair<int, int> P;

P dijkstra(int start, const vector<vector<P>> &graph)
{
    int n = graph.size() - 1;
    int cnt = 0, max_dist = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dist(n + 1, INF);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur])
            continue;

        for (const P &p : graph[cur])
        {
            const int &nxt = p.first;
            const int &d = p.second;
            if (cur_dist + d < dist[nxt])
            {
                dist[nxt] = cur_dist + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    for (size_t i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            max_dist = max(max_dist, dist[i]);
            cnt++;
        }
    }

    return {cnt, max_dist};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<P>> graph(n + 1);
        for (size_t i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        P ans = dijkstra(c, graph);
        cout << ans.first << " " << ans.second << '\n';
    }
}