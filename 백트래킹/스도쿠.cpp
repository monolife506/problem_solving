// 2580번: 스도쿠

#include <iostream>
#include <array>
using namespace std;

bool done = false;
bool flag = false;
array<array<int, 9>, 9> board = {};

void ans(int X, int Y)
{
    if (X == 9)
    {
        if (Y < 8)
            ans(0, Y + 1);
        else
            done = true;
    }
    else if (board[X][Y] != 0)
        ans(X + 1, Y);
    else
    {
        array<bool, 1 + 9> num = {};
        for (size_t i = 0; i < 9; i++) // 가로
        {
            if (board[i][Y] != 0)
                num[board[i][Y]] = true;
        }
        for (size_t j = 0; j < 9; j++) // 세로
        {
            if (board[X][j] != 0)
                num[board[X][j]] = true;
        }
        for (size_t i = (X / 3) * 3; i < 3 + (X / 3) * 3; i++) // 박스
        {
            for (size_t j = (Y / 3) * 3; j < 3 + (Y / 3) * 3; j++)
            {
                if (board[i][j] != 0)
                    num[board[i][j]] = true;
            }
        }

        // 채워보기
        flag = false;
        for (size_t i = 1; i <= 9; i++)
        {
            if (!num[i])
            {
                flag = true;
                board[X][Y] = i;
                ans(X + 1, Y);
                if (!flag)
                    board[X][Y] = 0;
            }
            if (done)
                return;
        }

        if (!flag)
            return;
    }
}

int main()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
            cin >> board[i][j];
    }

    ans(0, 0);
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if (j == 8)
                cout << '\n';
        }
    }
}