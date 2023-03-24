#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string t;
    cin >> t;

    vector<int> nxt(26, -1), pre(26, -1);
    vector<int> last(26);
    for (int i = 0; i < 26; ++i)
        last[i] = i;

    int cnt = 0;
    for (int i = 0; i < t.length(); ++i)
    {
        if (nxt[t[i] - 'a'] != -1)
        {
            cout << (char)('a' + nxt[t[i] - 'a']);
            continue;
        }

        for (int j = 0; j < 26; ++j)
        {
            if (j == t[i] - 'a')
                continue;

            if (pre[j] == -1 && (last[t[i] - 'a'] != j || cnt == 25))
            {
                nxt[t[i] - 'a'] = j;
                pre[j] = t[i] - 'a';
                last[j] = last[t[i] - 'a'];
                ++cnt;

                int cur = nxt[j];
                while (cnt != 26 && cur != -1)
                {
                    last[cur] = last[pre[cur]];
                    cur = nxt[cur];
                }

                cout << (char)('a' + j);
                break;
            }
        }
    }

    cout << '\n';
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

1
3
bca
ab

c -> b -> a
last(a) == c

a -> c

1
4
abcde
bcdef

c -> b -> a
a -> c

d -> c -> b -> a



*/