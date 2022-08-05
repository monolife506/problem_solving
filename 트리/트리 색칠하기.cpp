#include <iostream>
#include <vector>
using namespace std;

int C[200001];
vector<int> graph[200001];

int dfs(int cur, int parent, int color)
{
    int ret = 0;

    if (color != C[cur])
    {
        color = C[cur];
        ++ret;
    }

    for (int nxt : graph[cur])
    {
        if (nxt == parent)
            continue;

        ret += dfs(nxt, cur, color);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> C[i];
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(1, -1, 0) << '\n';
}