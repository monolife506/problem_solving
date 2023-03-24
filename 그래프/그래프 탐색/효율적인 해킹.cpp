#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10001];
bool visited[100001];
int cnt[100001];

void dfs(int cur)
{
    visited[cur] = true;
    cnt[cur]++;
    for (int nxt : graph[cur])
    {
        if (visited[nxt])
            continue;

        dfs(nxt);
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
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, cnt[i]);
    for (int i = 1; i <= N; ++i)
    {
        if (cnt[i] == ans)
            cout << i << " ";
    }

    cout << '\n';
}