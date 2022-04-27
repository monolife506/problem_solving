#include <iostream>
#include <string>
using namespace std;

int cache[4000][4000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (size_t i = 0; i < s1.size(); ++i)
    {
        for (size_t j = 0; j < s2.size(); ++j)
        {
            if (s1[i] == s2[j])
            {
                cache[i][j] = (i > 0 && j > 0) ? cache[i - 1][j - 1] + 1 : 1;
                ans = max(ans, cache[i][j]);
            }
        }
    }

    cout << ans << '\n';
}