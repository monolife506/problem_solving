#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int root[501];

int find(int n)
{
    if (root[n] == -1)
        return n;
    return root[n] = find(root[n]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        root[u] = v;
        return true;
    }

    return false;
}

int ccw(pii p, pii a, pii b)
{
    ll cross = 1LL * (a.first - p.first) * (b.second - p.second) - 1LL * (b.first - p.first) * (a.second - p.second);
    return (cross > 0) - (cross < 0);
}

ll get_dist(pii a, pii b)
{
    return 1LL * abs(a.first - b.first) * abs(a.first - b.first) + 1LL * abs(a.second - b.second) * abs(a.second - b.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int n, m;
    cin >> n >> m;

    vector<pii> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int node_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (root[i] == -1)
            node_cnt++;
    }

    vector<pair<ll, pii>> edges;
    for (int i = 1; i + 1 <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool flag = true;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j)
                    continue;

                int ccw_val = ccw(p[k], p[i], p[j]);
                bool x_flag = (min(p[i].first, p[j].first) < p[k].first && p[k].first < max(p[i].first, p[j].first));
                bool y_flag = (min(p[i].second, p[j].second) < p[k].second && p[k].second < max(p[i].second, p[j].second));
                if (ccw_val == 0 && x_flag && y_flag)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                edges.push_back(make_pair(-get_dist(p[i], p[j]), pii(i, j)));
        }
    }

    sort(edges.begin(), edges.end());

    int edge_cnt = 0;
    ll ans = 0;
    for (auto [d, tp] : edges)
    {
        if (edge_cnt == node_cnt - 1)
            break;
        if (merge(tp.first, tp.second))
        {
            edge_cnt++;
            ans += d;
        }
    }

    cout << -ans << '\n';
}