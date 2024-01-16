#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(10, 0);
    for (int i = 0; i < n; ++i)
        cnt[s[i] - '0']++;

    vector<int> ans(n, -1);
    for (int i = 9; i >= 1; --i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            if (ans[j] != -1 || ans[(n - 1) - j] != -1)
                continue;

            int l_num = s[j] - '0';
            int r_num = s[(n - 1) - j] - '0';
            if (l_num != r_num && max(l_num, r_num) == i && cnt[i] >= 1)
            {
                cnt[i]--;
                if (l_num > r_num)
                    ans[(n - 1) - j] = i;
                else
                    ans[j] = i;
            }
        }
        for (int j = 0; j < n / 2; ++j)
        {
            if (ans[j] != -1 || ans[(n - 1) - j] != -1)
                continue;

            int l_num = s[j] - '0';
            int r_num = s[(n - 1) - j] - '0';
            if (i > max(l_num, r_num) && cnt[i] >= 2)
            {
                cnt[i] -= 2;
                ans[j] = ans[(n - 1) - j] = i;
            }
        }
    }

    if (n % 2 == 1)
    {
        for (int i = 9; i > s[n / 2] - '0'; --i)
        {
            if (cnt[i] >= 1)
            {
                cnt[i]--;
                ans[n / 2] = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ((ans[i] != -1) ? ans[i] : (int)(s[i] - '0'));

    cout << '\n';
}

/*

5
11991
19991

6
113322
323323

8
11133221
32233223

8
21133221
322    3
*/