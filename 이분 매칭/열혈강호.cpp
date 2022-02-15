#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

size_t N, M;
vector<int> graph[1001]; // 주어진 이분 그래프

int matched[2][1001]; // 각 그룹에서 매치된 정점 번호
bool visited[1001];

bool match(int cur) // dfs를 이용한 매칭
{
    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[1][nxt] == -1 || (!visited[matched[1][nxt]] && match(matched[1][nxt])))
        {
            matched[0][cur] = nxt;
            matched[1][nxt] = cur;
            return true;
        }
    }

    return false;
}

int bipartite_matching()
{
    int match_cnt = 0;
    memset(matched, -1, sizeof(matched));
    for (size_t i = 1; i <= N; ++i)
    {
        if (matched[0][i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i))
                match_cnt++;
        }
    }

    return match_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
    {
        size_t work_cnt;
        cin >> work_cnt;
        for (size_t j = 0; j < work_cnt; ++j)
        {
            int work;
            cin >> work;
            graph[i].push_back(work);
        }
    }

    cout << bipartite_matching() << '\n';
}