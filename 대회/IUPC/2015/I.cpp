#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int INF = 987654321;

int T, N, K, S;

void init(vector<P>& arr)
{
    for (size_t i = 1; i <= N; i++) {
        cin >> S;
        arr[i].first = arr[i].second = 0;
        while (S % 2 == 0) {
            S /= 2;
            arr[i].first++;
        }
        while (S % 5 == 0) {
            S /= 5;
            arr[i].second++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (size_t tc = 0; tc < T; tc++) {
        cin >> N >> K;
        vector<P> arr(N + 1);
        vector<P> dp(N + 1);
        init(arr);

        dp[1] = arr[1];
        for (int i = 2; i <= N; i++) {
            dp[i] = P(INF, INF);
            for (int j = 1; j <= K; j++) {
                if (i - j <= 0)
                    break;
                dp[i].first = min(dp[i].first, dp[i - j].first + arr[i].first);
                dp[i].second = min(dp[i].second, dp[i - j].second + arr[i].second);
            }
        }

        cout << min(dp[N].first, dp[N].second) << '\n';
    }
}

// Trailing zero: 모든 수의 곱의 min(2, 5);

// (0, 1)
// (1, 0)
// (1, 0)
// (0, 1)
// (1, 1)
// (1, 0)
// (1, 0)
// (0, 0)