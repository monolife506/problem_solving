// 10026번: 적녹색약

#include <iostream>
using namespace std;

int N;
bool flag; // 적녹색약인가?
char img[101][101];

void dfs(int x, int y, bool visited[][101])
{
    visited[y][x] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    for (size_t i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
            continue;
        if (!visited[next_y][next_x])
        {
            char next_chr = img[next_y][next_x];
            char cur_chr = img[y][x];

            if (flag && (cur_chr == 'R' || cur_chr == 'G') && (next_chr == 'R' || next_chr == 'G'))
                dfs(next_x, next_y, visited);
            else if (cur_chr == next_chr)
                dfs(next_x, next_y, visited);
        }
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> img[i];

    int ans[2] = {};
    for (int k = 0; k < 2; k++)
    {
        flag = k;
        bool visited[101][101] = {};
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    dfs(j, i, visited);
                    ans[k]++;
                }
            }
        }
    }

    cout << ans[0] << " " << ans[1];
}