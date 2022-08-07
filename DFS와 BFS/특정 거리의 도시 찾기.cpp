#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

int N, M, K, X, dist[300001];
vector<int> graph[300001];

void bfs()
{
    queue<int> q;
    q.push(X);

    memset(dist, -1, sizeof(dist));
    dist[X] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[nxt] == -1)
            {
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    bfs();

    bool flag = false;
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] == K)
        {
            flag = true;
            cout << i << '\n';
        }
    }
    if (!flag)
    {
        cout << -1 << '\n';
    }
}