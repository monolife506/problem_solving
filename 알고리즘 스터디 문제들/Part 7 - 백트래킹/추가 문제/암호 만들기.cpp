#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
array<char, 15> pwd;
array<char, 15> chr;

// con_cnt == 자음의 개수
// vow_cnt == 모음의 개수
void backtrack(int min, int cnt, int vow_cnt, int con_cnt)
{
    if (cnt == L)
    {
        if (con_cnt >= 2 && vow_cnt >= 1)
        {
            for (size_t i = 0; i < L; i++)
                cout << pwd[i];
            cout << '\n';
        }
        return;
    }

    for (size_t i = min + 1; i < C; i++)
    {
        pwd[cnt] = chr[i];
        switch (chr[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            backtrack(i, cnt + 1, vow_cnt + 1, con_cnt);
            break;
        default:
            backtrack(i, cnt + 1, vow_cnt, con_cnt + 1);
        }
    }
}

int main()
{
    cin >> L >> C;
    for (size_t i = 0; i < C; i++)
        cin >> chr[i];

    sort(chr.begin(), chr.begin() + C);
    backtrack(-1, 0, 0, 0);
}