#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct Edge
{
    int from, to, w;
    Edge(int from = 0, int to = 0, int w = 0) : from(from), to(to), w(w) {}

    bool operator<(Edge &rhs) const { return w < rhs.w; }
};

struct DisjointSet
{
    int *root;

    DisjointSet(size_t n)
    {
        root = new int[n];
        memset(root, -1, sizeof(int) * n);
    }

    ~DisjointSet() { delete[] root; }

    int find(int n)
    {
        if (root[n] == -1)
            return n;
        return root[n] = find(root[n]);
    }

    bool merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        root[b] = a;
        return true;
    }
};

Edge edge[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i)
        cin >> edge[i].from >> edge[i].to >> edge[i].w;

    int edge_cnt = 0, ans = 0;
    DisjointSet root(N + 1);
    sort(edge, edge + M);
    for (size_t i = 0; i < M && edge_cnt < N - 1; ++i)
    {
        if (root.merge(edge[i].from, edge[i].to))
        {
            ++edge_cnt;
            ans += edge[i].w;
        }
    }

    cout << ans << '\n';
}