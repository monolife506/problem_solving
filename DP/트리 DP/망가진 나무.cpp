#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int idx, to;
    bool is_exist;
    Edge(int idx, int to, bool is_exist) : idx(idx), to(to), is_exist(is_exist) {}
};

vector<Edge> tree[100001];
int cache[100001];
bool is_reversed[100001];

int dfs(int cur, int parent)
{
    int ret = 0;
    for (Edge &e : tree[cur])
    {
        if (e.to == parent)
            continue;
        if (!e.is_exist)
            ++ret;

        ret += dfs(e.to, cur);
    }

    return ret;
}

void dfs2(int cur, int parent)
{
    for (Edge &e : tree[cur])
    {
        if (e.to == parent)
        {
            cache[cur] = (e.is_exist) ? cache[parent] - 1 : cache[parent] + 1;
            continue;
        }
    }

    for (Edge &e : tree[cur])
    {
        if (e.to == parent)
            continue;

        dfs2(e.to, cur);
    }
}

void dfs3(int cur, int parent)
{
    for (Edge &e : tree[cur])
    {
        if (e.to == parent)
            continue;
        if (!e.is_exist)
            is_reversed[e.idx] = true;

        dfs3(e.to, cur);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(Edge(i, v, true));
        tree[v].push_back(Edge(i, u, false));
    }

    cache[1] = dfs(1, -1);
    dfs2(1, -1);

    int idx = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (cache[idx] > cache[i])
            idx = i;
    }

    dfs3(idx, -1);
    for (int i = 0; i < N - 1; ++i)
        cout << is_reversed[i];

    cout << '\n';
}