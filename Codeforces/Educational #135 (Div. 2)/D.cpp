#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[2000][2000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (size_t tc = 0; tc < t; ++tc)
    {
        string s;
        cin >> s;

        memset(cache, -1, sizeof(cache));
        for (int i = 0; i + 1 < s.length(); ++i)
        {
            if (s[i] == s[i + 1])
                cache[i][i + 1] = 0;
            else
                cache[i][i + 1] = 1;
        }
        for (int d = 3; d < s.length(); d += 2)
        {
            for (int i = 0; i + d < s.length(); ++i)
            {
                int j = i + d;
                if ((s[i] == s[j] || s[i] == s[i + 1]) && (s[i] == s[j] || s[j - 1] == s[j]))
                {
                    if (s[i] == s[j])
                    {
                        cache[i][j] = max(cache[i][j], cache[i + 1][j - 1]);
                    }
                    else
                    {
                        cache[i][j] = max(cache[i][j], cache[i + 2][j]);
                        cache[i][j] = max(cache[i][j], cache[i][j - 2]);
                    }
                }
                else
                {
                    cache[i][j] = 1;
                }
            }
        }

        cout << (cache[0][s.length() - 1] == 1 ? "Alice" : "Draw") << '\n';
    }
}

/*

1 2

2 1

1 -- 2
2 -- 1


cbaabc

*/