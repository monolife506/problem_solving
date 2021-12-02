#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 200;
const int MAX_M = 20000;
const int INF = 4000001;

int N, M;
int graph[MAX_N + 1][MAX_N + 1];
pair<P, int> edges[MAX_M];

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
    double ret = 0;
    for (size_t i = 0; i < M; i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        double w = edges[i].second;

        ret = max(ret, (dist[start][u] + dist[start][v] + w) / 2);
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
        graph[S][E] = graph[E][S] = (graph[S][E] == -1) ? L : min(graph[S][E], L);
        edges[i] = make_pair(P(S, E), L);
    }

    floyd();

    double ans = INF;
    for (size_t i = 1; i <= N; i++)
        ans = min(ans, getIgnitionTime(i));

    cout << fixed << setprecision(1) << ans << '\n';
}

// w = (n - u) + (n - v)