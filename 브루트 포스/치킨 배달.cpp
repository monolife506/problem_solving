// 15686번: 치킨 배달

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

size_t N, M;
int map[50][50];
vector<P> chicken;

int BFS(vector<bool> &choice)
{
    queue<P> Q;
    int dist[50][50];

    memset(dist, -1, sizeof(dist));
    for (size_t i = 0; i < choice.size(); i++)
    {
        if (choice[i])
        {
            Q.push(P(chicken[i].first, chicken[i].second));
            dist[chicken[i].first][chicken[i].second] = 0;
        }
    }

    int total = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!Q.empty())
    {
        int curY = Q.front().first;
        int curX = Q.front().second;
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                continue;
            if (dist[nextY][nextX] == -1)
            {
                dist[nextY][nextX] = dist[curY][curX] + 1;
                Q.push(P(nextY, nextX));
                if (map[nextY][nextX] == 1)
                    total += dist[nextY][nextX];
            }
        }
    }

    return total;
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                chicken.push_back(P(i, j));
        }
    }

    vector<bool> choice(chicken.size(), false);
    for (size_t i = 0; i < M; i++)
        choice[i] = true;

    int ans = INT32_MAX;
    do
    {
        ans = min(ans, BFS(choice));
    } while (prev_permutation(choice.begin(), choice.end()));
    cout << ans;
}