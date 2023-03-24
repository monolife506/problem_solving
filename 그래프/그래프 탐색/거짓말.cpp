// 1043번: 거짓말

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<bool, int> P;

bool flag[51];
vector<int> knower;
vector<int> graph[2][51]; // 0 == 사람, 1 == 파티

void bfs(int start)
{
    queue<P> Q;
    bool visited[2][51];
    memset(visited, false, sizeof(visited));
    Q.push(P(false, start));

    while (!Q.empty())
    {
        P cur = Q.front();
        Q.pop();
        visited[cur.first][cur.second] = true;

        if (cur.first)
            flag[cur.second] = true;

        for (int node : graph[cur.first][cur.second])
        {
            if (!visited[!cur.first][node])
                Q.push(P(!cur.first, node));
        }
    }
}

int main()
{
    int N, M, K, ans = 0;
    cin >> N >> M >> K;
    for (size_t i = 0; i < K; i++)
    {
        int num;
        cin >> num;
        knower.push_back(num);
    }
    for (size_t i = 1; i <= M; i++)
    {
        int cnt;
        cin >> cnt;
        for (size_t j = 0; j < cnt; j++)
        {
            int num;
            cin >> num;
            graph[0][num].push_back(i);
            graph[1][i].push_back(num);
        }
    }

    for (int num : knower)
        bfs(num);

    for (size_t i = 1; i <= M; i++)
    {
        if (!flag[i])
            ans++;
    }
    cout << ans;
}

// 사람과 파티를 하나의 정점으로 할것