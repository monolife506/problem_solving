#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

struct Edge
{
    int to, c, f, d;
    Edge *rev = nullptr;
    Edge(int to, int c, int d) : to(to), c(c), f(0), d(d) {}

    int remain()
    {
        return c - f;
    }
    void add(int flow)
    {
        f += flow;
        rev->f -= flow;
    }
};

void add_edge(int u, int v, int c, int d, vector<vector<Edge *>> &graph)
{
    Edge *e = new Edge(v, c, d);
    Edge *e_rev = new Edge(u, 0, -d);
    e->rev = e_rev;
    e_rev->rev = e;
    graph[u].push_back(e);
    graph[v].push_back(e_rev);
}

int mcmf(int S, int T, vector<vector<Edge *>> &graph)
{
    int min_cost = 0;
    while (true)
    {
        queue<int> q;
        vector<int> pre(graph.size(), -1);
        vector<Edge *> path(graph.size(), nullptr);
        vector<int> dist(graph.size(), INF);
        vector<bool> in_queue(graph.size(), false);

        q.push(S);
        in_queue[S] = true;
        dist[S] = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            in_queue[cur] = false;
            for (Edge *e : graph[cur])
            {
                if (e->remain() > 0 && dist[e->to] > dist[cur] + e->d)
                {
                    dist[e->to] = dist[cur] + e->d;
                    pre[e->to] = cur;
                    path[e->to] = e;
                    if (!in_queue[e->to])
                    {
                        q.push(e->to);
                        in_queue[e->to] = true;
                    }
                }
            }
        }

        if (pre[T] == -1)
            break;

        int flow = INF;
        for (int i = T; i != S; i = pre[i])
            flow = min(flow, path[i]->remain());
        for (int i = T; i != S; i = pre[i])
        {
            path[i]->add(flow);
            min_cost += path[i]->d;
        }
    }

    return min_cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge *>> graph(N + 2);
    add_edge(0, 1, 2, 0, graph);
    add_edge(N, N + 1, 2, 0, graph);
    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        add_edge(A, B, 1, C, graph);
        add_edge(B, A, 1, C, graph);
    }

    cout << mcmf(0, N + 1, graph) << '\n';
}