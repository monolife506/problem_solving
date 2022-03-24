#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

size_t N;

vector<int> network[502]; // 0: source, N + 1: sink
int c[502][502], f[502][502], level[502], work[502];
bool visited[502];

// level graph의 존재 여부 확인
bool dinic_bfs(int source, int sink)
{
    queue<int> q;
    q.push(source);
    memset(level, -1, sizeof(level));
    level[source] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : network[cur])
        {
            if (c[cur][nxt] - f[cur][nxt] > 0 && level[nxt] == -1)
            {
                q.push(nxt);
                level[nxt] = level[cur] + 1;
            }
        }
    }

    return level[sink] != -1;
}

// level graph의 blocking flow를 return
int dinic_dfs(int cur, int sink, int flow)
{
    if (cur == sink)
        return flow;

    for (int &i = work[cur]; i < network[cur].size(); ++i)
    {
        int nxt = network[cur][i];
        if (level[cur] + 1 == level[nxt] && c[cur][nxt] - f[cur][nxt] > 0)
        {
            int ret = dinic_dfs(nxt, sink, min(c[cur][nxt] - f[cur][nxt], flow));

            if (ret > 0)
            {
                f[cur][nxt] += ret;
                f[nxt][cur] -= ret;
                return ret;
            }
        }
    }

    return 0;
}

// Dinic's Algorithm
int maximum_flow(int source, int sink)
{
    int total_flow = 0;
    while (dinic_bfs(source, sink))
    {
        memset(work, 0, sizeof(work));
        while (true)
        {
            int flow = dinic_dfs(source, sink, INF);
            if (flow == 0)
                break;
            total_flow += flow;
        }
    }

    return total_flow;
}

// minimum cut으로 진영 분류
void dfs(int cur)
{
    visited[cur] = true;
    for (int nxt : network[cur])
    {
        if (c[cur][nxt] - f[cur][nxt] > 0 && !visited[nxt])
            dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        int team;
        cin >> team;
        if (team == 1)
        {
            c[0][i] = INF;
            network[0].push_back(i);
            network[i].push_back(0);
        }
        else if (team == 2)
        {
            c[i][N + 1] = INF;
            network[i].push_back(N + 1);
            network[N + 1].push_back(i);
        }
    }
    for (size_t i = 1; i <= N; ++i)
    {
        for (size_t j = 1; j <= N; ++j)
        {
            cin >> c[i][j];
            if (i != j)
                network[i].push_back(j);
        }
    }

    cout << maximum_flow(0, N + 1) << '\n';

    dfs(0);
    for (size_t i = 1; i <= N; ++i)
    {
        if (visited[i])
            cout << i << " ";
    }
    cout << '\n';
    for (size_t i = 1; i <= N; ++i)
    {
        if (!visited[i])
            cout << i << " ";
    }
    cout << '\n';
}