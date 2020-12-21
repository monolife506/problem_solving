#include <iostream>
#include <cctype>
using namespace std;

int N, maxNum = -10000, minNum = 10000;
char board[5][5];

void dfs(int row, int col, int cur)
{
    if (row == N - 1 && col == N - 1)
    {
        maxNum = max(maxNum, cur);
        minNum = min(minNum, cur);
        return;
    }

    if (isdigit(board[row][col])) // 현재 칸은 숫자
    {
        if (row < N - 1)
            dfs(row + 1, col, cur);
        if (col < N - 1)
            dfs(row, col + 1, cur);
    }
    else // 현재 칸은 부호
    {
        if (row < N - 1)
        {
            switch (board[row][col])
            {
            case '+':
                dfs(row + 1, col, cur + (board[row + 1][col] - '0'));
                break;
            case '-':
                dfs(row + 1, col, cur - (board[row + 1][col] - '0'));
                break;
            case '*':
                dfs(row + 1, col, cur * (board[row + 1][col] - '0'));
                break;
            }
        }
        if (col < N - 1)
        {
            switch (board[row][col])
            {
            case '+':
                dfs(row, col + 1, cur + (board[row][col + 1] - '0'));
                break;
            case '-':
                dfs(row, col + 1, cur - (board[row][col + 1] - '0'));
                break;
            case '*':
                dfs(row, col + 1, cur * (board[row][col + 1] - '0'));
                break;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, board[0][0] - '0');
    cout << maxNum << " " << minNum;
}