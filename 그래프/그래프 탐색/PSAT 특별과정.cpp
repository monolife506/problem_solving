#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 987654321;

vector<int> graph[1000000];
char chr[1000001], ans[1000001];
int dist[2][1000000], pre[1000000], min_d = INF;

int N, M;
char S, E;

void bfs()
{
    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (chr[i] == E)
        {
            q.push(i);
            dist[0][i] = 0;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[0][nxt] > dist[0][cur] + 1)
            {
                dist[0][nxt] = dist[0][cur] + 1;
                pre[nxt] = cur;
                q.push(nxt);
            }
            else if (dist[0][nxt] == dist[0][cur] + 1 && chr[cur] < chr[pre[nxt]])
            {
                pre[nxt] = cur;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (chr[i] == S)
            min_d = min(min_d, dist[0][i]);
    }
}

void bfs2()
{
    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (chr[i] == S && dist[0][i] == min_d)
        {
            dist[1][i] = 0;
            q.push(i);
        }
    }

    ans[0] = S;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (pre[cur] == -1 || chr[cur] != ans[dist[1][cur]])
            continue;

        for (int nxt : graph[cur])
        {
            if (chr[pre[cur]] == chr[nxt] && dist[1][nxt] == INF && dist[0][nxt] + 1 == dist[0][cur])
            {
                dist[1][nxt] = dist[1][cur] + 1;
                ans[dist[1][nxt]] = min(ans[dist[1][nxt]], chr[nxt]);
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
    memset(pre, -1, sizeof(pre));
    fill_n(&dist[0][0], 2 * 1000000, INF);
    fill_n(ans, 1000001, 'a');

    cin >> N >> M >> S >> E >> chr;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    bfs();

    if (min_d == INF)
    {
        cout << "Aaak!" << '\n';
        return 0;
    }

    bfs2();

    for (int i = 0; i <= min_d; ++i)
        cout << ans[i];

    cout << '\n';
}

/*

6 6
A F
ABECDF
1 2
2 3
3 6
1 4
4 5
5 6

ABEF

5 5
A F
ACCDF
1 2
1 4
2 3
3 5
4 5

ADF

5 4
A F
ABACF
1 2
3 4
2 5
4 5

ABF


8 9
A B
ACCCHGFB
1 2
1 3
1 4
2 5
3 6
4 7
5 8
6 8
7 8

ACFB


9 7
A F
ACDFAABEF
1 2
2 3
3 4
5 6
6 7
7 8
8 9


*/