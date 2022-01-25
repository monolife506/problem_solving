#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int cache[100001];

int traverse(int cur, int parent)
{
    if (cache[cur] != -1)
        return cache[cur];

    int ret = 1;
    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;
        ret += traverse(nxt, cur);
    }

    return cache[cur] = ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    int N, R, Q;
    cin >> N >> R >> Q;
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    traverse(R, -1);
    for (size_t i = 0; i < Q; i++)
    {
        int u;
        cin >> u;
        cout << cache[u] << '\n';
    }
}