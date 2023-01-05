#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int cnt[3] = {0, 0, 0};
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> p;

        if (p != i && p == n - (i - 1))
            cnt[0]++;
        if (p == i && p != n - (i - 1))
            cnt[1]++;
        if (p != i && p != n - (i - 1))
            cnt[2]++;
    }

    bool turn = true;
    int tie_cnt = 0;
    while (tie_cnt < 2)
    {
        if (turn)
        {
            if (cnt[0] == 0 && cnt[2] == 0)
            {
                cout << "First" << '\n';
                return;
            }

            if (cnt[0] > 0)
                cnt[0]--;
            else if (cnt[2] > 1 || (cnt[1] > 0 && cnt[2] == 1))
                cnt[2]--;
            else
                tie_cnt++;
        }
        else
        {

            if (cnt[1] == 0 && cnt[2] == 0)
            {
                cout << "Second" << '\n';
                return;
            }

            if (cnt[1] > 0)
                cnt[1]--;
            else if (cnt[2] > 1 || (cnt[0] > 0 && cnt[2] == 1))
                cnt[2]--;
            else
                tie_cnt++;
        }

        turn = !turn;
    }

    cout << "Tie" << '\n';
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

/*

3 0 2
2 0 2
2 0 1
1 0 1
1 0 0


*/