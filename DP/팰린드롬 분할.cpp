#include <iostream>
#include <string>
using namespace std;

int dp[2500];
bool palin[2500][2500];

int main()
{
    string str;
    cin >> str;

    int N = str.size();

    for (int i = 0; i < N; i++)
        palin[i][i] = true;

    for (int i = 0; i + 1 < N; i++)
        palin[i][i + 1] = (str[i] == str[i + 1]);

    for (int d = 2; d < N; d++)
        for (int i = 0; i + d < N; i++)
            if (str[i] == str[i + d] && palin[i + 1][i + d - 1])
                palin[i][i + d] = true;

    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = 5000;
        for (int j = 0; j < i; j++) {
            if (palin[j + 1][i])
                dp[i] = min(dp[i], dp[j] + 1);
        }
        if (palin[0][i])
            dp[i] = 1;
    }

    cout << dp[N - 1] << '\n';
}
