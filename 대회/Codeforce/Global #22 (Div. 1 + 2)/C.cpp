#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[2][2][101][101];

int dp(bool turn, bool status, int even_cnt, int odd_cnt)
{
    if (even_cnt == 0 && odd_cnt == 0)
    {
        return status;
    }

    int &ret = cache[turn][status][even_cnt][odd_cnt];
    if (ret != -1)
        return ret;

    if (!turn)
    {
        int sel_even = 2, sel_odd = 2;
        if (even_cnt >= 1)
            sel_even = dp(!turn, status, even_cnt - 1, odd_cnt);
        if (odd_cnt >= 1)
            sel_odd = dp(!turn, !status, even_cnt, odd_cnt - 1);
        return ret = min(sel_even, sel_odd);
    }
    else
    {
        int sel_even = -1, sel_odd = -1;
        if (even_cnt >= 1)
            sel_even = dp(!turn, status, even_cnt - 1, odd_cnt);
        if (odd_cnt >= 1)
            sel_odd = dp(!turn, status, even_cnt, odd_cnt - 1);
        return ret = max(sel_even, sel_odd);
    }
}

void solve()
{
    int n;
    cin >> n;

    int even_cnt = 0, odd_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        a += 1e9;
        if (a % 2 == 0)
            even_cnt++;
        else
            odd_cnt++;
    }

    cout << (dp(false, false, even_cnt, odd_cnt) ? "Bob" : "Alice") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1
4
1 2 3 4

*/