#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

struct Edge
{
    int u;
    int v;
    bool flag = false; // 지워질 수 있는 간선인가

    Edge(int _u, int _v) : u(_u), v(_v) {}
};

int N, M, K;
vector<int> graph[MAX_N + 1];

char visited[MAX_N + 1]; // -1 or 1, 0 if not visited
int red_cnt = 0;
int black_cnt = 0;

void dfs(int cur, int cur_set)
{
    visited[cur] = cur_set;
    (cur_set == 1) ? red_cnt++ : black_cnt++;

    for (int next : graph[cur])
        if (visited[next] == 0)
            dfs(next, -cur_set);
}

bool isBipartite()
{
    for (size_t i = 1; i <= N; i++)
        if (visited[i] == 0)
            dfs(i, 1);

    for (size_t i = 1; i <= N; i++)
        for (int next : graph[i])
            if (visited[i] == visited[next])
                return false;

    return true;
}

int getCnt(vector<Edge> &edges, vector<int> &order)
{
    // 가장 많은 쌍을 지운 경우 이분 그래프인가?
    for (size_t i = 0; i < M; i++)
    {
        Edge &edge = edges[i];
        if (!edge.flag)
        {
            graph[edge.u].push_back(edge.v);
            graph[edge.v].push_back(edge.u);
        }
    }

    if (!isBipartite())
        return -1;

    // 역순으로 추적하며 어떤 간선을 추가할 때 까지 이분 그래프 조건을 유지하는지 확인
    for (int i = K - 1; i >= 0; i--)
    {
        if (visited[edges[order[i]].u] == visited[edges[order[i]].v])
            return i + 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<Edge> edges;
    vector<int> order;
    cin >> N >> M >> K;

    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(Edge(u, v));
    }

    for (size_t i = 0; i < K; i++)
    {
        int r;
        cin >> r;
        order.push_back(r - 1);
        edges[r - 1].flag = true;
    }

    int ans = getCnt(edges, order);
    cout << ans << '\n';

    if (ans != -1)
        cout << min(red_cnt, black_cnt) << " " << max(red_cnt, black_cnt) << '\n';
}