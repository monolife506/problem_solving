#include <iostream>
#include <array>
using namespace std;

bool solved = false;
array<array<int, 9>, 9> sudoku;

void solve(int r, int c)
{
    if (r == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << " ";
            cout << '\n';
        }

        solved = true;
        return;
    }
    else if (c == 9)
    {
        solve(r + 1, 0);
        return;
    }
    else if (sudoku[r][c] != 0)
    {
        solve(r, c + 1);
        return;
    }

    bool used[10] = {}; // 사용한 숫자를 확인하는 배열
    for (int i = 0; i < 9; i++)
    {
        used[sudoku[i][c]] = true;
        used[sudoku[r][i]] = true;
        used[sudoku[((r / 3) * 3) + (i / 3)][((c / 3) * 3) + (i % 3)]] = true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!used[i])
        {
            sudoku[r][c] = i;
            solve(r, c + 1);
        }

        if (solved)
            return;
    }
    sudoku[r][c] = 0;
}

int main()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
            cin >> sudoku[i][j];
    }

    solve(0, 0);
}