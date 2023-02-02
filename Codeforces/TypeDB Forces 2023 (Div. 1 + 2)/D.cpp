#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a[200001], dfsn[200001], root[200001], max_dfsn[200001], component_sz;
bool reachable[200001];

void dfs(int cur, int nth)
{
    dfsn[cur] = nth;
    component_sz++;

    int nxt = cur + a[cur];
    if (nxt >= 1 && nxt <= n && dfsn[nxt] == -1)
        dfs(nxt, nth + 1);
}

void dfs2(int cur)
{
    int nxt = cur + a[cur];
    if (nxt >= 1 && nxt <= n && dfsn[nxt] == -1)
        dfs2(nxt);

    if (dfsn[nxt] != -1)
        max_dfsn[cur] = dfsn[nxt];
    else
        max_dfsn[cur] = max_dfsn[nxt];
}

int find(int n)
{
    return (root[n] < 0) ? n : root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        reachable[a] = (reachable[a] || reachable[b]);
        root[a] += root[b];
        root[b] = a;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        dfsn[i] = -1;
        root[i] = -1;
        reachable[i] = false;
    }

    component_sz = 0;
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (i + a[i] >= 1 && i + a[i] <= n)
            merge(i, i + a[i]);
        else
            reachable[find(i)] = true;
    }

    ll ans = 0;
    if (reachable[find(1)])
    {
        for (int i = 1; i <= n; ++i)
        {
            if (find(i) == find(1) && dfsn[i] == -1)
                dfs2(i);
        }

        ans += 1LL * n * (n + 1);
        for (int i = 1; i <= n; ++i)
        {
            ans += n - component_sz;
            if (dfsn[i] != -1)
                ans += dfsn[i];
            else if (find(i) == find(1))
                ans += max_dfsn[i];
            else if (reachable[find(i)])
                ans += component_sz;
        }
    }
    else
    {
        ans += 1LL * component_sz * (n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (reachable[find(i)])
                ans += component_sz;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1
3
2 -1 1

*/