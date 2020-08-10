// 1197번: 최소 스패닝 트리
// 최소 신장 트리 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int root[10001];

struct Edge
{
    int u;
    int v;
    int w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator<(const Edge &U) const { return this->w < U.w; }
};

int find(int N)
{
    if (root[N] == -1)
        return N;
    return root[N] = find(root[N]);
}

bool merge(int U, int V)
{
    U = find(U);
    V = find(V);
    if (U != V)
    {
        root[U] = V;
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<Edge> edges;
    memset(root, -1, sizeof(root));

    int V, E;
    cin >> V >> E;
    for (size_t i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end());

    int edgeCnt = 0;
    int totalWeight = 0;
    for (size_t i = 0; edgeCnt < V - 1; i++)
    {
        if (!merge(edges[i].u, edges[i].v))
        {
            edgeCnt++;
            totalWeight += edges[i].w;
        }
    }

    cout << totalWeight;
}