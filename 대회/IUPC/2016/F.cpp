#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1000000;

bool check(int num, vector<bool>& cards)
{
    string str = to_string(num);
    for (char chr : str) {
        if (!cards[chr - '0'])
            return false;
    }
    return true;
}

int getCnt(int num, vector<bool>& cards, vector<int>& dp)
{
    if (dp[num] != MAX)
        return dp[num];

    if (check(num, cards)) {
        dp[num] = 0;
        return dp[num];
    }

    for (size_t i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            dp[num] = min(dp[num], getCnt(num / i, cards, dp) + getCnt(i, cards, dp) + 1);
        }
    }

    return dp[num];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, M, K;
        vector<bool> cards(10, false);
        vector<int> dp(MAX + 1, MAX);

        cin >> N;
        for (size_t i = 0; i < N; i++) {
            cin >> K;
            cards[K] = true;
        }

        cin >> M;
        for (size_t i = 0; i < M; i++) {
            cin >> K;

            int ans = getCnt(K, cards, dp);
            cout << ((ans == MAX) ? -1 : ans) << '\n';
        }
    }
}