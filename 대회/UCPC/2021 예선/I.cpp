#include <cstring>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int board[1 << 11][1 << 11];

void solve(int k, int y, int x, int a, int b, int color)
{
    if (k == 1)
    {
        for (int i = y; i < y + 2; ++i)
        {
            for (int j = x; j < x + 2; ++j)
            {
                if (i != a || j != b)
                    board[i][j] = color;
            }
        }

        return;
    }

    int len = (1 << k);
    if (a - y < len / 2 && b - x < len / 2)
    {
        solve(k - 1, y, x, a, b, 1);
        solve(k - 1, y, x + len / 2, y + len / 2 - 1, x + len / 2, 2);
        solve(k - 1, y + len / 2, x, y + len / 2, x + len / 2 - 1, 2);
        solve(k - 1, y + len / 2, x + len / 2, y + len / 2, x + len / 2, 1);
    }
    else if (a - y < len / 2 && b - x >= len / 2)
    {
        solve(k - 1, y, x, y + len / 2 - 1, x + len / 2 - 1, 1);
        solve(k - 1, y, x + len / 2, a, b, 2);
        solve(k - 1, y + len / 2, x, y + len / 2, x + len / 2 - 1, 2);
        solve(k - 1, y + len / 2, x + len / 2, y + len / 2, x + len / 2, 1);
    }
    else if (a - y >= len / 2 && b - x < len / 2)
    {
        solve(k - 1, y, x, y + len / 2 - 1, x + len / 2 - 1, 1);
        solve(k - 1, y, x + len / 2, y + len / 2 - 1, x + len / 2, 2);
        solve(k - 1, y + len / 2, x, a, b, 2);
        solve(k - 1, y + len / 2, x + len / 2, y + len / 2, x + len / 2, 1);
    }
    else // a - y >= len / 2 && b - x >= len / 2
    {
        solve(k - 1, y, x, y + len / 2 - 1, x + len / 2 - 1, 1);
        solve(k - 1, y, x + len / 2, y + len / 2 - 1, x + len / 2, 2);
        solve(k - 1, y + len / 2, x, y + len / 2, x + len / 2 - 1, 2);
        solve(k - 1, y + len / 2, x + len / 2, a, b, 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, k;
    cin >> T >> k;
    for (int tc = 0; tc < T; ++tc)
    {
        int a, b;
        cin >> a >> b;

        memset(board, 0, sizeof(board));
        solve(k, 1, 1, a, b, 1);
        for (int i = 1; i <= (1 << k); ++i)
        {
            for (int j = 1; j <= (1 << k); ++j)
            {
                if (board[i][j] == 0)
                    cout << (i == a && j == b ? "@" : "c");
                else if (board[i][j] == 1)
                    cout << "a";
                else // board[i][j] == 2
                    cout << "b";
            }

            cout << '\n';
        }
    }
}