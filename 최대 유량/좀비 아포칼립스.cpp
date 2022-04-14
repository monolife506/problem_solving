#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

struct Edge
{
    int to, c, f = 0;
    Edge *reverse_edge = nullptr;
    Edge(int to = -1, int c = 0) : to(to), c(c) {}

    int remain()
    {
        return c - f;
    }
    void add(int flow)
    {
        f += flow;
        reverse_edge->f -= flow;
    }
};

int maximum_flow(int source, int sink, vector<vector<Edge *>> &graph)
{
    int ret = 0;
    while (true)
    {
        queue<int> q;
        vector<int> pre(graph.size(), -1);
        vector<Edge *> path(graph.size(), nullptr);
        q.push(source);
        while (!q.empty() && pre[sink] == -1)
        {
            int cur = q.front();
            q.pop();
            for (Edge *e : graph[cur])
            {
                if (e->remain() > 0 && pre[e->to] == -1)
                {
                    q.push(e->to);
                    pre[e->to] = cur;
                    path[e->to] = e;
                }
            }
        }

        if (pre[sink] == -1)
            break;

        int flow = INF;
        for (int i = sink; i != source; i = pre[i])
            flow = min(flow, path[i]->remain());
        for (int i = sink; i != source; i = pre[i])
            path[i]->add(flow);

        ret += flow;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        int N, I, G, S, M, R;
        cin >> N >> I >> G >> S;

        vector<vector<Edge *>> graph(N * (S + 1) + 2);
        Edge *e = new Edge(I, G);
        Edge *er = new Edge(0, 0);
        e->reverse_edge = er;
        er->reverse_edge = e;
        graph[0].push_back(e);
        graph[I].push_back(er);
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j + 1 <= S; ++j)
            {
                Edge *e = new Edge(N * (j + 1) + i, INF);
                Edge *er = new Edge(N * j + i, 0);
                e->reverse_edge = er;
                er->reverse_edge = e;
                graph[N * j + i].push_back(e);
                graph[N * (j + 1) + i].push_back(er);
            }
        }

        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            int x;
            cin >> x;
            for (int j = 0; j <= S; ++j)
            {
                Edge *e = new Edge(N * (S + 1) + 1, INF);
                Edge *er = new Edge(N * j + x, 0);
                e->reverse_edge = er;
                er->reverse_edge = e;
                graph[N * j + x].push_back(e);
                graph[N * (S + 1) + 1].push_back(er);
            }
        }

        cin >> R;
        for (int i = 0; i < R; ++i)
        {
            int a, b, p, t;
            cin >> a >> b >> p >> t;
            for (int j = 0; j + t <= S; ++j)
            {
                Edge *e = new Edge(N * (j + t) + b, p);
                Edge *er = new Edge(N * j + a, 0);
                e->reverse_edge = er;
                er->reverse_edge = e;
                graph[N * j + a].push_back(e);
                graph[N * (j + t) + b].push_back(er);
            }
        }

        cout << maximum_flow(0, N * (S + 1) + 1, graph) << '\n';
    }
}