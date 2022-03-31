#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool ans, visited[101];

void dfs(int cur)
{
    visited[cur] = true;
    for (int next : graph[cur]) {
        if (visited[next]) {
            ans = true;
            return;
        }
        dfs(next);
    }
    visited[cur] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 1; i < N; i++) {
        int M;
        cin >> M;
        for (size_t j = 0; j < M; j++) {
            int C;
            cin >> C;
            graph[i].push_back(C);
        }
    }

    dfs(1);
    cout << (ans ? "CYCLE" : "NO CYCLE");
}