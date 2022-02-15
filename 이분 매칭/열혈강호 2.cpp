#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2001];
int matched[2][2001];
bool visited[2001];

bool match(int cur)
{
    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[1][nxt] == -1 || (!visited[matched[1][nxt]]) && match(matched[1][nxt]))
        {
            matched[0][cur] = nxt;
            matched[1][nxt] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(matched, -1, sizeof(matched));

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
    {
        size_t work_cnt;
        cin >> work_cnt;
        for (size_t j = 0; j < work_cnt; j++)
        {
            size_t work;
            cin >> work;
            graph[i * 2 - 1].push_back(work);
            graph[i * 2].push_back(work);
        }
    }

    int ans = 0;
    for (size_t i = 1; i <= 2 * N; ++i)
    {
        if (matched[0][i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i))
                ans++;
        }
    }

    cout << ans << '\n';
}