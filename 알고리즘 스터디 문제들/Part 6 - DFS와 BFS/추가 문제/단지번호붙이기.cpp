#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};

int N, cnt;                     // 지도의 크기, 단지 내 집의 수
array<array<bool, 26>, 26> map; // 주어진 지도 (방문 여부도 확인)
vector<int> estate;             // 각 단지내 집의 수를 저장하는 vector

// 모든 칸을 탐색해야 하므로 DFS로 탐색함
// x, y == 현재 탐색하는 칸을 나타냄 (map[y][x])
// cnt == 현재 탐색하는 단지 내 집의 수
void dfs(int x, int y)
{
    cnt++;
    map[y][x] = false;
    for (size_t i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= N)
            continue;
        if (next_y < 0 || next_y >= N)
            continue;
        if (map[next_y][next_x])
            dfs(next_x, next_y);
    }
}

int main()
{
    cin >> N;
    string input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        for (size_t j = 0; j < N; j++)
            map[i][j] = input[j] - '0';
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cnt = 0;
            if (map[i][j])
            {
                dfs(j, i);
                estate.push_back(cnt);
            }
        }
    }

    sort(estate.begin(), estate.end());
    cout << estate.size() << '\n';
    for (size_t i = 0; i < estate.size(); i++)
        cout << estate[i] << '\n';
}
