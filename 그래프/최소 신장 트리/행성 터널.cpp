// 2887번: 행성 터널

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int root[100001];

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
        return true;
    }
    return false;
}

struct Node
{
    int num, x, y, z;
    Node(int _num, int _x, int _y, int _z) : num(_num), x(_x), y(_y), z(_z) {}
};

struct Edge
{
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &U) { return this->w < U.w; }
};

struct sortX
{
    bool operator()(const Node &U, const Node &V) { return U.x < V.x; }
};
struct sortY
{
    bool operator()(const Node &U, const Node &V) { return U.y < V.y; }
};
struct sortZ
{
    bool operator()(const Node &U, const Node &V) { return U.z < V.z; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(root, -1, sizeof(root));

    vector<Node> nodes;
    vector<Edge> edges;

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        nodes.push_back(Node(i, x, y, z));
    }

    sort(nodes.begin(), nodes.end(), sortX());
    for (size_t i = 0; i < nodes.size() - 1; i++)
        edges.push_back(Edge(nodes[i].num, nodes[i + 1].num, abs(nodes[i].x - nodes[i + 1].x)));
    sort(nodes.begin(), nodes.end(), sortY());
    for (size_t i = 0; i < nodes.size() - 1; i++)
        edges.push_back(Edge(nodes[i].num, nodes[i + 1].num, abs(nodes[i].y - nodes[i + 1].y)));
    sort(nodes.begin(), nodes.end(), sortZ());
    for (size_t i = 0; i < nodes.size() - 1; i++)
        edges.push_back(Edge(nodes[i].num, nodes[i + 1].num, abs(nodes[i].z - nodes[i + 1].z)));

    size_t cnt = 0;
    ll cost = 0;
    sort(edges.begin(), edges.end());
    for (size_t i = 0; cnt < N - 1; i++)
    {
        if (merge(edges[i].u, edges[i].v))
        {
            cnt++;
            cost += edges[i].w;
        }
    }

    cout << cost;
}