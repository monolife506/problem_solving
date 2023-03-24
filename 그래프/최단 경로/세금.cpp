#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 1000;
const int MAX_K = 30000;
const int INF = 30000001;

int N;
vector<P> graph[MAX_N + 1];
int dist[MAX_N + 1][MAX_N + 1];

void dijkstra(int start, int dest)
{
    fill(&dist[0][0], &dist[MAX_N][MAX_N + 1], INF);
    priority_queue<pair<P, int>, vector<pair<P, int>>, greater<pair<P, int>>> pq;
    pq.push(make_pair(P(dist[0][0] = 0, 0), start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_dist = pq.top().first.first;
        int edge_cnt = pq.top().first.second;
        pq.pop();

        if (edge_cnt == N - 1)
            continue;

        if (dist[edge_cnt][cur] < cur_dist)
            continue;

        for (P &p : graph[cur])
        {
            int nxt = p.first;
            int w = p.second;

            if (dist[edge_cnt + 1][nxt] > cur_dist + w)
            {
                dist[edge_cnt + 1][nxt] = cur_dist + w;
                pq.push(make_pair(P(dist[edge_cnt + 1][nxt], edge_cnt + 1), nxt));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, K, S, D;
    cin >> N >> M >> K >> S >> D;
    for (size_t i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(P(b, w));
        graph[b].push_back(P(a, w));
    }

    dijkstra(S, D);

    int cost = 0; // 현재 세금
    for (size_t i = 0; i <= K; i++)
    {
        int ans = INF;
        for (int j = 1; j <= N - 1; j++)
            ans = min(ans, dist[j][D] + j * cost);

        cout << ans << '\n';

        if (i != K)
        {
            int p;
            cin >> p;
            cost += p;
        }
    }
}

/*
cost + (n - 1) * k_sum
*/