#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t t;
    cin >> t;
    for (size_t tc = 0; tc < t; tc++) {
        string s1, s2;
        cin >> s1 >> s2;

        int max_len = 0;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
        for (size_t i = 0; i <= s1.length(); i++) {
            for (size_t j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }

        cout << (s1.length() - max_len) + (s2.length() - max_len) << '\n';
    }
}