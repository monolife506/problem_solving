#include <iostream>
using namespace std;

int N, T;
char str[500001];

void swap_str(int l, int r, char win)
{
    int cnt = 0;
    for (int i = l; i <= r; ++i)
    {
        if (str[i] == win)
        {
            ++cnt;
            continue;
        }

        char tmp = str[i];
        str[i] = str[i - min(T, cnt)];
        str[i - min(T, cnt)] = tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> T >> str;

    bool r_flag = false, s_flag = false, p_flag = false;

    int start = 0;
    for (int i = 0; i < N; ++i)
    {
        if (str[i] == 'R')
            r_flag = true;
        else if (str[i] == 'S')
            s_flag = true;
        else // str[i] == 'P'
            p_flag = true;

        if (r_flag && s_flag && p_flag)
        {

            if (str[i] == 'R')
                swap_str(start, i - 1, 'S');
            else if (str[i] == 'S')
                swap_str(start, i - 1, 'P');
            else // str[i] == 'P'
                swap_str(start, i - 1, 'R');

            r_flag = (str[i] == 'R');
            s_flag = (str[i] == 'S');
            p_flag = (str[i] == 'P');
            start = i;
        }
    }

    if (r_flag && s_flag)
        swap_str(start, N - 1, 'R');
    else if (r_flag && p_flag)
        swap_str(start, N - 1, 'P');
    else if (s_flag && p_flag)
        swap_str(start, N - 1, 'S');

    cout << str << '\n';
}

/*

매 iteration마다
RS -> SR (S가 한칸 뒤로)
SP -> PS (P가 한칸 뒤로)
PR -> RP (R이 한칸 뒤로)

RSSS -> SSSR

*/