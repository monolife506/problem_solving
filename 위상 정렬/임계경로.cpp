#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 10000;

int N;
vector<P> graph[MAX_N + 1];

bool visited[MAX_N + 1];
int indegree[MAX_N + 1];
int dist[MAX_N + 1]; // 현재 노드의 최장 거리

P getCriticalPath(int start, int dest)
{
    queue<int> Q;
    for (size_t i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
            visited[i] = true;
        }
    }

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (visited[cur])
            continue;

        for (P &p : graph[cur])
        {
            int &next = p.first;
            int &w = p.second;

            if (dist[cur] + w > dist[next])
                dist[next] = dist[cur] + w;

            if (--indegree[next] == 0)
                Q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, start, dest;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(P(v, w));
        indegree[v]++;
    }

    cin >> start >> dest;

    P ans = getCriticalPath(start, dest);
    cout << ans.first << '\n'
         << ans.second << '\n';
}