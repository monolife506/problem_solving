#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 987654321;

int spf[300001], dist[600001], pre[600001];
vector<int> graph[600001];

void sieve()
{
    for (ll i = 2; i <= 300000; ++i)
        spf[i] = i;
    for (ll i = 2; i * i <= 300000; i++)
    {
        if (spf[i] != i)
            continue;
        for (ll j = i * i; j <= 300000; j += i)
            spf[j] = i;
    }
}

void bfs(int s)
{
    queue<int> q;
    fill_n(&dist[0], 600001, INF);
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[nxt] > dist[cur] + 1)
            {
                dist[nxt] = dist[cur] + 1;
                pre[nxt] = cur;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        while (a != 1)
        {
            graph[i].push_back(spf[a] + 300000);
            graph[spf[a] + 300000].push_back(i);
            a /= spf[a];
        }
    }

    int s, t;
    cin >> s >> t;

    bfs(s);
    if (dist[t] == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << (dist[t] / 2) + 1 << '\n';

        stack<int> st;

        int cur = t;
        while (cur != 0)
        {
            if (cur <= 300000)
                st.push(cur);

            cur = pre[cur];
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << '\n';
    }
}