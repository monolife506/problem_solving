#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int N, L, R, population[2][100][100];
bool visited[100][100];

bool bfs(P start)
{
    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {-1, 0, 1, 0};

    queue<P> q;
    vector<P> v;

    visited[start.first][start.second] = true;
    v.push_back(start);
    int sum = population[0][start.first][start.second];
    q.push(start);

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
                continue;
            if (!visited[nxt_y][nxt_x] && abs(population[0][y][x] - population[0][nxt_y][nxt_x]) >= L && abs(population[0][y][x] - population[0][nxt_y][nxt_x]) <= R)
            {
                visited[nxt_y][nxt_x] = true;
                v.push_back({nxt_y, nxt_x});
                sum += population[0][nxt_y][nxt_x];
                q.push({nxt_y, nxt_x});
            }
        }
    }

    if (v.size() == 1)
        return false;

    for (P &p : v)
        population[1][p.first][p.second] = sum / v.size();

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> population[0][i][j];
    }

    int ans = 0;
    while (true)
    {
        memset(population[1], -1, sizeof(population[1]));
        memset(visited, false, sizeof(visited));

        bool flag = false;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j])
                    continue;
                if (bfs({i, j}))
                    flag = true;
            }
        }

        if (!flag)
            break;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (population[1][i][j] != -1)
                    population[0][i][j] = population[1][i][j];
            }
        }

        ++ans;
    }

    cout << ans << '\n';
}