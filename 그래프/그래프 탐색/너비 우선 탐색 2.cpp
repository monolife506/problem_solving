#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 100000;
const int INF = 987654321;

vector<int> adj[MAX_N + 1];
int bfsn[MAX_N + 1];

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    int nth = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        bfsn[cur] = ++nth;
        for (int nxt : adj[cur])
        {
            if (bfsn[nxt] == 0)
            {
                bfsn[nxt] = -1;
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

    size_t N, M, R;
    cin >> N >> M >> R;
    for (size_t i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (size_t i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end(), greater<int>());

    bfs(R);
    for (size_t i = 1; i <= N; ++i)
        cout << bfsn[i] << '\n';
}