#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2][1001];
int matched[2][1001];
bool visited[2][1001];

bool match(int cur)
{
    if (visited[0][cur])
        return false;

    visited[0][cur] = true;
    for (int nxt : graph[0][cur])
    {
        if (matched[1][nxt] == -1 || match(matched[1][nxt]))
        {
            matched[0][cur] = nxt;
            matched[1][nxt] = cur;
            return true;
        }
    }

    return false;
}

void dfs(bool flag, int cur) // using alternating path
{
    visited[flag][cur] = true;
    for (int nxt : graph[flag][cur])
    {
        if (visited[!flag][nxt])
            continue;

        if (!flag && matched[flag][cur] != nxt)
            dfs(!flag, nxt);
        else if (flag && matched[flag][cur] == nxt)
            dfs(!flag, nxt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;
    for (size_t cur = 1; cur <= N; ++cur)
    {
        size_t cnt;
        cin >> cnt;
        for (size_t i = 0; i < cnt; ++i)
        {
            size_t nxt;
            cin >> nxt;
            graph[0][cur].push_back(nxt);
            graph[1][nxt].push_back(cur);
        }
    }

    int match_cnt = 0;
    memset(matched, -1, sizeof(matched));
    for (size_t i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i);
    }

    vector<int> a, b;
    memset(visited, false, sizeof(visited));
    for (size_t i = 1; i <= N; i++)
    {
        if (matched[0][i] == -1)
            dfs(false, i);
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (!visited[0][i])
            a.push_back(i);
    }
    for (size_t i = 1; i <= M; ++i)
    {
        if (visited[1][i])
            b.push_back(i);
    }

    cout << match_cnt << '\n';

    cout << a.size() << " ";
    for (int i : a)
        cout << i << " ";
    cout << '\n';

    cout << b.size() << " ";
    for (int j : b)
        cout << j << " ";
    cout << '\n';
}

/*


1 -- 2
2 -- 1
3 -- 3
4 -- 4

*/