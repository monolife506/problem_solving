#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int num[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
const int num2[8] = {-1, -1, 1, 7, 4, 2, 6, 8};

ll cache[19][101];
ll ans[19][101];

void solve()
{
    int n;
    cin >> n;

    ll min_num = INF;
    for (int i = 1; i <= 18; ++i)
    {
        if (ans[i][n] == INF)
            continue;

        if (to_string(ans[i][n]).size() != i || (i == 1 && ans[i][n] == 0))
        {
            min_num = min(min_num, (ll)pow(10, i - 1) * 6 + ans[i][n]);
        }
        else
        {
            min_num = min(min_num, ans[i][n]);
        }
    }

    string max_num;
    if (n % 2 == 0)
    {
        for (int i = n; i > 0; i -= 2)
            max_num.push_back('1');
    }
    else
    {
        max_num.push_back('7');
        for (int i = n - 3; i > 0; i -= 2)
            max_num.push_back('1');
    }

    cout << min_num << " " << max_num << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 19 * 101, INF);
    fill_n(&ans[0][0], 19 * 101, INF);

    for (int i = 2; i <= 7; ++i)
    {
        cache[1][i] = num[i];
        ans[1][i] = num2[i];
    }

    for (int j = 2; j <= 18; ++j)
    {
        for (int i = 8; i <= 100; ++i)
        {
            for (int k = 2; k <= 7; ++k)
            {
                if (cache[j - 1][i - k] == INF)
                    continue;

                cache[j][i] = min(cache[j][i], (ll)pow(10, j - 1) * num[k] + cache[j - 1][i - k]);
                ans[j][i] = min(ans[j][i], (ll)pow(10, j - 1) * num2[k] + cache[j - 1][i - k]);
            }
        }
    }

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
        solve();
}

/*

1: 2

7: 3

4: 4

2: 5
3: 5
5: 5

0: 6
6: 6
9: 6

8: 7


n == 8 -> 2 6, 3 5, 4 4, 5 3, 6 2
n == 10 -> 2 8,

188
202


*/