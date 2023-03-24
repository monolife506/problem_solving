#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int R, C;
char mineral[MAX + 1][MAX + 1];

bool visited[MAX + 1][MAX + 1], floating[MAX + 1][MAX + 1];

void dfs(int y, int x, bool is_floating)
{
    visited[y][x] = true;
    floating[y][x] = is_floating;

    for (size_t i = 0; i < 4; i++)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= R || nxt_x < 0 || nxt_x >= C)
            continue;
        if (mineral[nxt_y][nxt_x] == '.' || visited[nxt_y][nxt_x])
            continue;

        dfs(nxt_y, nxt_x, is_floating);
    }
}

void update(int d, int r)
{
    memset(visited, false, sizeof(visited));
    memset(floating, false, sizeof(floating));

    for (int j = (d == 1) ? 0 : C - 1; j >= 0 && j < C; j += d)
    {
        if (mineral[r][j] == 'x')
        {
            mineral[r][j] = '.';
            break;
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (mineral[i][j] == 'x' && !visited[i][j])
                dfs(i, j, (i != 0));

    int fall_height = MAX + 1;
    for (int j = 0; j < C; j++)
    {
        int max_height = 0;
        for (int i = 0; i < R; i++)
        {
            if (mineral[i][j] == 'x')
            {
                if (floating[i][j])
                {
                    fall_height = min(fall_height, i - max_height);
                    break;
                }

                max_height = i + 1;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (floating[i][j])
            {
                mineral[i - fall_height][j] = mineral[i][j];
                mineral[i][j] = '.';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (int i = R - 1; i >= 0; i--)
        cin >> mineral[i];

    int N, d = 1;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int r;
        cin >> r;
        update(d, r - 1);
        d *= -1;
    }

    for (int i = R - 1; i >= 0; i--)
        cout << mineral[i] << '\n';
}

/*
*****
*...*
*...*
....*
*****
*/