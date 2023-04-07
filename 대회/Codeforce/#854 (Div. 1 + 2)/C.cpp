#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    string s;
    cin >> s;

    int cnt[26] = {};
    for (char c : s)
        cnt[c - 'a']++;

    string prefix, surfix;
    for (int i = 0; i < 26; ++i)
    {
        while (cnt[i] >= 2)
        {
            prefix.push_back('a' + i);
            surfix.push_back('a' + i);
            cnt[i] -= 2;
        }

        if (cnt[i] == 1)
        {
            int flag = 0, idx = 0;
            for (int j = i + 1; j < 26; ++j)
            {
                if (cnt[j] != 0)
                {
                    flag++;
                    idx = j;
                }
            }

            if (flag == 0)
            {
                prefix.push_back('a' + i);
            }
            else if (flag == 1)
            {
                for (int j = 0; j < ((cnt[idx] + 2 - 1) / 2); ++j)
                    prefix.push_back('a' + idx);
                prefix.push_back('a' + i);
                for (int j = 0; j < (cnt[idx] / 2); ++j)
                    prefix.push_back('a' + idx);
            }
            else
            {
                for (int j = i + 1; j < 26; ++j)
                {
                    while (cnt[j] != 0)
                    {
                        prefix.push_back('a' + j);
                        cnt[j]--;
                    }
                }
                prefix.push_back('a' + i);
            }

            break;
        }
    }

    reverse(surfix.begin(), surfix.end());

    cout << prefix + surfix << '\n';
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