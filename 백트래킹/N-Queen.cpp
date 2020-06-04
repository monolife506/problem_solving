// 9663번: N-Queen

#include <iostream>
#include <array>
#include <cmath>
using namespace std;

int N;
int cnt = 0;
array<int, 1 + 15> board = {};
void ans(int line)
{
    if (line == N)
    {
        cnt += 1;
        return;
    }

    for (int X = 1; X <= N; X++)
    {
        bool flag = true;
        for (int i = 1; i <= line; i++)
        {
            if (board[i] == X || abs(X - board[i]) == abs((line + 1) - i))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            board[line + 1] = X;
            ans(line + 1);
        }
    }
}

int main()
{
    cin >> N;
    ans(0);
    cout << cnt;
}