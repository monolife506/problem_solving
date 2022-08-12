#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[101];

bool visited[101];
int matched[5001];

bool match(int cur)
{
    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[nxt] == -1 || (!visited[matched[nxt]] && match(matched[nxt])))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int max_match()
{
    memset(matched, -1, sizeof(matched));

    int match_cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i);
    }

    return match_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cout << max_match() << '\n';
}
