#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, dist[200001], pre[200001];

void bfs(int start)
{
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    memset(pre, -1, sizeof(pre));

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur > 0 && dist[cur - 1] == -1)
        {
            dist[cur - 1] = dist[cur] + 1;
            pre[cur - 1] = cur;
            q.push(cur - 1);
        }
        if (cur < 200000 && dist[cur + 1] == -1)
        {
            dist[cur + 1] = dist[cur] + 1;
            pre[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (cur <= 100000 && dist[cur * 2] == -1)
        {
            dist[cur * 2] = dist[cur] + 1;
            pre[cur * 2] = cur;
            q.push(cur * 2);
        }
    }
}

void solve()
{
    int k;
    cin >> n >> k;

    bfs(n);

    cout << dist[k] << endl;

    stack<int> s;
    int cur = k;
    while (cur != -1)
    {
        s.push(cur);
        cur = pre[cur];
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
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