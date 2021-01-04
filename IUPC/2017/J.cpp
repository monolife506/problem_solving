#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int root = -1;
    char gender;
};

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w)
        : u(_u)
        , v(_v)
        , w(_w)
    {
    }

    bool operator<(const Edge& E) const { return w < E.w; }
};

vector<Node> nodes(1001);
vector<Edge> edges;

int find(int n)
{
    if (nodes[n].root < 0)
        return n;
    return nodes[n].root = find(nodes[n].root);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    nodes[b].root = a;
    return true;
}

int main()
{
    int N, M, ans = 0, cnt = 0;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
        cin >> nodes[i].gender;
    for (size_t i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (nodes[u].gender != nodes[v].gender)
            edges.push_back(Edge(u, v, d));
    }

    sort(edges.begin(), edges.end());
    for (size_t i = 0; i < edges.size(); i++) {
        if (merge(edges[i].u, edges[i].v)) {
            ans += edges[i].w;
            if (++cnt == N - 1) {
                cout << ans;
                return 0;
            }
        }
    }

    cout << -1;
}