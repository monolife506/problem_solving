#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> graph[10];

void bfs(vector<int> &start, map<vector<int>, int> &dist)
{
    queue<vector<int>> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        vector<int> cur_p = q.front();
        q.pop();

        int cur;
        for (int i = 0; i < 9; ++i)
        {
            if (cur_p[i] == 0)
            {
                cur = i;
                break;
            }
        }

        for (int nxt : graph[cur])
        {
            vector<int> nxt_p = cur_p;
            swap(nxt_p[cur], nxt_p[nxt]);
            if (dist.find(nxt_p) == dist.end())
            {
                dist[nxt_p] = dist[cur_p] + 1;
                q.push(nxt_p);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> start(9);
    for (int i = 1; i <= 8; ++i)
    {
        int p;
        cin >> p;
        start[p - 1] = i;
    }

    map<vector<int>, int> dist;
    bfs(start, dist);

    vector<int> dest = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    cout << (dist.find(dest) != dist.end() ? dist[dest] : -1) << '\n';
}