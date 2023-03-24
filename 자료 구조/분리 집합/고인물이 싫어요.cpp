#include <cstring>
#include <iostream>
using namespace std;

int root[100001], clean[100001], dirty[100001];

int find(int n)
{
    if (root[n] == -1)
        return n;
    else
        return root[n] = find(root[n]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        clean[u] += clean[v];
        dirty[u] += dirty[v];
        root[v] = u;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    size_t N, M, Q;
    cin >> N >> M >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        bool is_clean;
        cin >> is_clean;

        if (is_clean)
            ++clean[i];
        else
            ++dirty[i];
    }
    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    for (size_t i = 0; i < Q; i++)
    {
        int k;
        cin >> k;

        k = find(k);
        cout << (clean[k] > dirty[k]) << '\n';
    }
}