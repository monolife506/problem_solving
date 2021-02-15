#include <iostream>
using namespace std;

int N, ans[2];
bool board[10][10];
bool bishop[10][10];

bool check(int x, int y)
{
    for (int i = -N; i <= N; i++)
    {
        bool flag1 = (x + i >= 0 && x + i < N && y + i >= 0 && y + i < N);
        bool flag2 = (x + i >= 0 && x + i < N && y - i >= 0 && y - i < N);

        if (flag1 && bishop[y + i][x + i])
            return false;

        if (flag2 && bishop[y - i][x + i])
            return false;
    }

    return true;
}

void backtracking(int x, int y, int cnt, bool is_white)
{
    if (x >= N)
    {
        backtracking((y + is_white) % 2, y + 1, cnt, is_white);
        return;
    }

    if (y >= N)
    {
        ans[is_white] = max(ans[is_white], cnt);
        return;
    }

    if (!board[y][x])
    {
        backtracking(x + 2, y, cnt, is_white);
        return;
    }

    backtracking(x + 2, y, cnt, is_white); // 놓지 않음
    if (check(x, y))
    {
        bishop[y][x] = true;
        backtracking(x + 2, y, cnt + 1, is_white); // 놓음
        bishop[y][x] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    backtracking(0, 0, 0, true);
    backtracking(1, 0, 0, false);
    cout << ans[0] + ans[1];
}