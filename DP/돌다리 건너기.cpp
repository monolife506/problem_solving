#include <iostream>
#include <string>
using namespace std;

int cache[2][20][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string pat, s1, s2;
    cin >> pat >> s1 >> s2;

    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == pat[0])
            cache[0][0][i] = 1;
        if (s2[i] == pat[0])
            cache[1][0][i] = 1;
    }
    for (int i = 1; i < pat.length(); ++i)
    {
        for (int j = 1; j < s1.length(); ++j)
        {
            if (s1[j] == pat[i])
            {
                for (int k = 0; k < j; ++k)
                {
                    if (s2[k] == pat[i - 1])
                        cache[0][i][j] += cache[1][i - 1][k];
                }
            }
            if (s2[j] == pat[i])
            {
                for (int k = 0; k < j; ++k)
                {
                    if (s1[k] == pat[i - 1])
                        cache[1][i][j] += cache[0][i - 1][k];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        ans += cache[0][pat.length() - 1][i];
        ans += cache[1][pat.length() - 1][i];
    }

    cout << ans << '\n';
}