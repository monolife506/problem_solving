#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 10000;

int N, M, start, dest;
vector<P> graph[MAX_N + 1];
vector<P> graph_reverse[MAX_N + 1];

bool visited[MAX_N + 1];
int indegree[MAX_N + 1];
int dist[MAX_N + 1]; // 현재 노드의 최장 거리

int getDist()
{
    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
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

    return dist[dest];
}

int getPathCnt(int cur)
{
    if (cur == start)
        return 0;

    int ret = 0;
    visited[cur] = true;

    for (P &p : graph_reverse[cur])
    {
        int &next = p.first;
        int &w = p.second;

        if (dist[cur] - w == dist[next])
            ret += (visited[next]) ? 1 : getPathCnt(next) + 1;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(P(v, w));
        graph_reverse[v].push_back(P(u, w));
        indegree[v]++;
    }

    cin >> start >> dest;
    cout << getDist() << '\n';

    memset(visited, false, sizeof(visited));
    cout << getPathCnt(dest) << '\n';
}