#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    vector<string> board(8);
    for (int i = 0; i < 8; ++i)
        cin >> board[i];

    for (int i = 0; i < 8; ++i)
    {
        bool flag = true;
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] != 'R')
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << 'R' << '\n';
            return;
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        bool flag = true;
        for (int j = 0; j < 8; ++j)
        {
            if (board[j][i] != 'B')
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << 'B' << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}