#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = 1e18;

vector<pii> graph[1001];
ll dist[1001];
int pre[1001];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill_n(&dist[0], 1001, INF);
    memset(pre, -1, sizeof(pre));
    pq.push({dist[start] = 0, start});

    while (!pq.empty())
    {
        int cur_d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur_d > dist[cur])
            continue;

        for (auto [nxt, w] : graph[cur])
        {
            if (dist[nxt] > dist[cur] + w)
            {
                pq.push({dist[nxt] = dist[cur] + w, nxt});
                pre[nxt] = cur;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);

    cout << dist[t] << endl;

    int cur = t;
    stack<int> st;
    while (cur != -1)
    {
        st.push(cur);
        cur = pre[cur];
    }

    cout << st.size() << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}