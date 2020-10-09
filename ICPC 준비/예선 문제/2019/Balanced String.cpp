#include <iostream>
using namespace std;

int dp[100001];

int main()
{
    int N;
    cin >> N;

    dp[2] = dp[1] = 2;
    for (size_t i = 3; i <= N; i++) {
        if (i % 2 == 1) {
            dp[i] = dp[i - 1] * 2;
            dp[i] %= 16769023;
        } else
            dp[i] = dp[i - 1];
    }

    cout << dp[N];
}

// 0 1
// 01 10
// 011 010 101 100
// 0110 0101 1010 1001