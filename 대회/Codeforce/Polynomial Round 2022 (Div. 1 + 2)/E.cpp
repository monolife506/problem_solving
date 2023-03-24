#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, d, m1, m2, max_a[200001], max_b[200001], cache[200001];
vector<int> tree[200001];
bool a[200001], b[200001];

void dfs(int cur, int parent, int depth)
{
    if (a[cur])
        max_a[cur] = depth;
    if (b[cur])
        max_b[cur] = depth;

    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        dfs(nxt, cur, depth + 1);
        if (max_a[nxt] == -1 && max_b[nxt] == -1)
            continue;

        if (min(max_a[nxt], max_b[nxt]) == -1 && max(max_a[nxt], max_b[nxt]) - depth <= d)
            cache[cur] += cache[nxt] + 1;
        else
            cache[cur] += cache[nxt] + 2;

        max_a[cur] = max(max_a[cur], max_a[nxt]);
        max_b[cur] = max(max_b[cur], max_b[nxt]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(max_a, -1, sizeof(max_a));
    memset(max_b, -1, sizeof(max_b));

    cin >> n >> d;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cin >> m1;
    a[1] = true;
    for (int i = 0; i < m1; ++i)
    {
        int u;
        cin >> u;
        a[u] = true;
    }

    cin >> m2;
    b[1] = true;
    for (int i = 0; i < m2; ++i)
    {
        int u;
        cin >> u;
        b[u] = true;
    }

    dfs(1, -1, 0);
    cout << cache[1] * 2 << '\n';
}

/*

d == 2


*/