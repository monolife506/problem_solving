#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, in[2][200001], out[2][200001], cache[200001];
pii e[200000];
vector<int> graph[200001];

int topological_sort()
{
    int ret = 1;

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        cache[i] = 1;
        if (in[0][i] == 0)
            q.push(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            cache[nxt] = max(cache[nxt], cache[cur] + 1);
            ret = max(ret, cache[nxt]);
            if (--in[0][nxt] == 0)
                q.push(nxt);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        in[0][v]++;
        in[1][v]++;
        out[0][u]++;
        out[1][u]++;

        e[i] = {u, v};
    }
    for (int i = 0; i < m; ++i)
    {
        int &u = e[i].first;
        int &v = e[i].second;

        if (in[1][v] == 1 || out[1][u] == 1)
        {
            in[0][v]--;
            out[0][u]--;
        }
        else
        {
            graph[u].push_back(v);
        }
    }

    cout << topological_sort() << '\n';
}

/*


1 2
1 3
2 3

1 (2, 0)
2 (1, 1)
3 (2, 0)

*/