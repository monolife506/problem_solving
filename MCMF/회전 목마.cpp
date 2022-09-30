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

    int remain_capacity()
    {
        return c - f;
    }
    void add_flow(int flow)
    {
        f += flow;
        rev->f -= flow;
    }
};

vector<Edge *> graph[2002];

int mcmf(int S, int T)
{
    int min_cost = 0;
    while (true)
    {
        queue<int> q;
        vector<int> pre(2002, -1);
        vector<Edge *> path(2002, nullptr);
        vector<int> dist(2002, INF);
        vector<bool> in_queue(2002, false);

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
                if (e->remain_capacity() > 0 && dist[e->to] > dist[cur] + e->d)
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
            flow = min(flow, path[i]->remain_capacity());
        for (int i = T; i != S; i = pre[i])
        {
            path[i]->add_flow(flow);
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

    int N;
    cin >> N;

    int S = N;
    int T = N + 1;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;

        Edge *e, *e_rev;

        e = new Edge(i, a, 0);
        e_rev = new Edge(S, 0, 0);
        e->rev = e_rev;
        e_rev->rev = e;
        graph[S].push_back(e);
        graph[i].push_back(e_rev);

        e = new Edge((i + 1) % N, INF, 1);
        e_rev = new Edge(i, 0, -1);
        e->rev = e_rev;
        e_rev->rev = e;
        graph[i].push_back(e);
        graph[(i + 1) % N].push_back(e_rev);

        e = new Edge((i + N - 1) % N, INF, 1);
        e_rev = new Edge(i, 0, -1);
        e->rev = e_rev;
        e_rev->rev = e;
        graph[i].push_back(e);
        graph[(i + N - 1) % N].push_back(e_rev);

        e = new Edge(T, 1, 0);
        e_rev = new Edge(i, 0, 0);
        e->rev = e_rev;
        e_rev->rev = e;
        graph[i].push_back(e);
        graph[T].push_back(e_rev);
    }

    cout << mcmf(S, T) << '\n';
}