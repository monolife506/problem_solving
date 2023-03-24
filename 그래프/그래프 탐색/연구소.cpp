// 14502번: 연구소

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, M, ans = 0;
int map[8][8];

vector<P> safe;
vector<P> virus;
vector<P> newWall;

int bfs()
{
    for (size_t i = 0; i < 3; i++)
        map[newWall[i].first][newWall[i].second] = 1;

    queue<P> Q;
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    for (P &place : virus)
    {
        Q.push(P(place.first, place.second));
        visited[place.first][place.second] = true;
    }

    int virusCnt = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!Q.empty())
    {
        int curX = Q.front().second;
        int curY = Q.front().first;
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int X = curX + dx[i];
            int Y = curY + dy[i];
            if (X >= M || X < 0 || Y >= N || Y < 0)
                continue;
            if (map[Y][X] != 1 && !visited[Y][X])
            {
                virusCnt++;
                Q.push(P(Y, X));
                visited[Y][X] = true;
            }
        }
    }

    for (size_t i = 0; i < 3; i++)
        map[newWall[i].first][newWall[i].second] = 0;

    return safe.size() - virusCnt - 3;
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                safe.push_back(P(i, j));
            else if (map[i][j] == 2)
                virus.push_back(P(i, j));
        }
    }

    vector<bool> choice(safe.size(), false);
    choice[0] = choice[1] = choice[2] = true;
    do
    {
        for (size_t i = 0; i < choice.size(); i++)
        {
            if (choice[i])
                newWall.push_back(safe[i]);
        }

        ans = max(ans, bfs());
        newWall.clear();
    } while (prev_permutation(choice.begin(), choice.end()));

    cout << ans;
}