#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2][100001];
bool visited[2][100001];

void dfs(int cur, int i)
{
    visited[i][cur] = true;
    for (int nxt : graph[i][cur])
    {
        if (visited[i][nxt])
            continue;

        dfs(nxt, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int X, Y;
        cin >> X >> Y;
        graph[0][X].push_back(Y);
        graph[1][Y].push_back(X);
    }

    dfs(1, 0);
    dfs(N, 1);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int C;
        cin >> C;
        cout << (visited[0][C] && visited[1][C] ? "Defend the CTP" : "Destroyed the CTP") << '\n';
    }
}