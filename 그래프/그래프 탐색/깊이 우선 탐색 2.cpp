#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

vector<int> graph[MAX_N + 1];
int in[MAX_N + 1];

void dfs(int cur)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : graph[cur])
    {
        if (in[nxt] == 0)
            dfs(nxt);
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (size_t i = 1; i <= N; ++i)
        sort(graph[i].begin(), graph[i].end(), greater<int>());

    dfs(R);
    for (size_t i = 1; i <= N; ++i)
        cout << in[i] << '\n';
}