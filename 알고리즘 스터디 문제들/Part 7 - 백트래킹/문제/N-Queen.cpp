#include <iostream>
#include <array>
using namespace std;

int N;
int ans = 0;
array<array<bool, 15>, 15> board = {}; // 체스판에 퀸이 있는 칸을 확인하는 배열

void nQueen(int x, int y)
{
    // 세로 방향, 가로는 판단하지 않음
    for (int i = 0; i < N; i++)
    {
        if (board[i][x])
            return;
    }

    // 대각선 방향
    for (int i = 0; i < N; i++)
    {
        if (x + i < N && y + i < N)
        {
            if (board[y + i][x + i])
                return;
        }
        if (x - i >= 0 && y + i < N)
        {
            if (board[y + i][x - i])
                return;
        }
        if (x + i < N && y - i >= 0)
        {
            if (board[y - i][x + i])
                return;
        }
        if (x - i >= 0 && y - i >= 0)
        {
            if (board[y - i][x - i])
                return;
        }
    }

    if (y + 1 == N)
    {
        ans++;
        return;
    }

    board[y][x] = true;
    for (size_t i = 0; i < N; i++)
        nQueen(i, y + 1);
    board[y][x] = false;
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        nQueen(i, 0);
    cout << ans;
}