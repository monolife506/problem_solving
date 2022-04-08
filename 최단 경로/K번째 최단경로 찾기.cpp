#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

size_t n, m, k;
vector<P> graph[1001];
priority_queue<int> dist[1001];

void dijkstra()
{
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});
    dist[1].push(0);

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (P &p : graph[cur])
        {
            int &nxt = p.first;
            int &w = p.second;
            if (dist[nxt].size() < k || dist[nxt].top() > d + w)
            {
                if (dist[nxt].size() == k)
                    dist[nxt].pop();
                dist[nxt].push(d + w);
                pq.push({d + w, nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra();
    for (size_t i = 1; i <= n; ++i)
        cout << (dist[i].size() == k ? dist[i].top() : -1) << '\n';
}