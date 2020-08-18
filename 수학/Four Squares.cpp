// 17626번: Four Squares

#include <iostream>
#include <vector>
using namespace std;

int dp[50001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> nums;

    cin >> N;
    for (int i = 1; i * i <= N; i++)
        nums.push_back(i * i);

    dp[0] = 0;
    dp[1] = 1;
    for (size_t i = 2; i <= N; i++)
    {
        int minCnt = 100000;
        for (size_t j = 0; nums[j] <= i && j < nums.size(); j++)
        {
            int prevNum = i - nums[j];
            minCnt = min(minCnt, dp[prevNum]);
        }

        dp[i] = minCnt + 1;
    }

    cout << dp[N];
}

// 1 1
// 2 2
// 3 3
// 4 1
// 5 2
// 6 3
// 7 4
// 8 2
// 9 1
// 10 2
// 11 3
// 12