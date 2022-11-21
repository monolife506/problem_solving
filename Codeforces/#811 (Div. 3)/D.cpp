#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string t;
    cin >> t;

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    vector<pair<int, int>> ans;

    int cur = 0;
    while (true)
    {
        int cnt = 0;
        pair<int, int> p;
        for (int i = 0; i < n; ++i) // 고른 s
        {
            for (int j = 0; j <= cur; ++j) // 시작 위치
            {
                bool flag = true;

                int tmp = 0;
                for (int k = 0; k < s[i].length(); ++k)
                {
                    if (j + k == t.length())
                    {
                        flag = false;
                        break;
                    }
                    if (t[j + k] != s[i][k])
                    {
                        flag = false;
                        break;
                    }

                    if (j + k >= cur)
                        ++tmp;
                }

                if (flag && tmp > cnt)
                {
                    cnt = tmp;
                    p = {i, j};
                }
            }
        }

        if (cnt == 0)
            break;

        ans.push_back(p);
        cur = p.second + s[p.first].length();
    }

    if (cur != t.length())
    {
        cout << -1 << '\n';
        return;
    }

    cout << ans.size() << '\n';
    for (pair<int, int> p : ans)
        cout << p.first + 1 << " " << p.second + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1
abcdef
3
bcde
abc
def

2

1
abacabaca
3
aba
bac
aca

4

*/