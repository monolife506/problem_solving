#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 200;
const int MAX_M = 20000;
const int INF = 4000001;

int N, M;
int graph[MAX_N + 1][MAX_N + 1];
vector<pair<P, int>> edges;

int dist[MAX_N + 1][MAX_N + 1];

void floyd()
{
    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            dist[i][j] = (graph[i][j] != -1) ? graph[i][j] : INF;

    for (size_t k = 1; k <= N; k++)
        for (size_t i = 1; i <= N; i++)
            for (size_t j = 1; j <= N; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

double getIgnitionTime(int start)
{
    double ret = -1;
    for (pair<P, int> &p : edges)
    {
        int u = p.first.first;
        int v = p.first.second;
        double w = p.second;

        double diff = abs(dist[start][u] - dist[start][v]);

        if (diff >= w)
        {
            ret = max(ret, dist[start][v] + w);
            continue;
        }

        ret = max(ret, (diff + w) / 2 + min(dist[start][u], dist[start][v]));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(graph, -1, sizeof(graph));
    for (size_t i = 1; i <= MAX_N; i++)
        graph[i][i] = 0;

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int S, E, L;
        cin >> S >> E >> L;
        graph[S][E] = graph[E][S] = (graph[S][E] == 0) ? L : min(graph[S][E], L);
        edges.push_back(make_pair(P(S, E), L));
    }

    floyd();

    double ans = INF;
    for (size_t i = 1; i <= N; i++)
        ans = min(ans, getIgnitionTime(i));

    cout << fixed << setprecision(1) << ans << '\n';
}

// w = (n - diff) + n