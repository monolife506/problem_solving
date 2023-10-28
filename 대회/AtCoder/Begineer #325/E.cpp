#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e12;

int n;
ll a, b, c, d[1001][1001], dist[2][1001];

void dijkstra(int s)
{
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    pq.push({dist[0][s] = 0, {0, s}});

    while (!pq.empty())
    {
        ll cur_d = pq.top().first;
        int is_train = pq.top().second.first;
        int cur = pq.top().second.second;
        pq.pop();

        if (is_train == 0)
        {
            if (dist[1][cur] > dist[0][cur])
            {
                dist[1][cur] = dist[0][cur];
                pq.push({dist[1][cur], {1, cur}});
            }

            for (int i = 1; i <= n; ++i)
            {
                if (cur == i)
                    continue;

                if (dist[0][i] > dist[0][cur] + d[cur][i] * a)
                {
                    dist[0][i] = dist[0][cur] + d[cur][i] * a;
                    pq.push({dist[0][i], {0, i}});
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (cur == i)
                    continue;

                if (dist[1][i] > dist[1][cur] + d[cur][i] * b + c)
                {
                    dist[1][i] = dist[1][cur] + d[cur][i] * b + c;
                    pq.push({dist[1][i], {1, i}});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dist[0][0], 2 * 1001, INF);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];
    }

    dijkstra(1);
    cout << dist[1][n] << '\n';
}