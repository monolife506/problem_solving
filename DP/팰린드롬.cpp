// 10942번: 팰린드롬?

#include <iostream>
#include <array>
using namespace std;

array<int, 2001> num;
array<array<bool, 2001>, 2001> dp = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, E;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> num[i];
        dp[i][i] = true;
    }

    for (size_t i = 1; i < N; i++)
    {
        if (num[i] == num[i + 1])
            dp[i][i + 1] = true;
    }

    for (size_t d = 2; d < N; d++)
    {
        for (size_t i = 1; i + d <= N; i++)
        {
            if (dp[i + 1][i + d - 1] && num[i] == num[i + d])
                dp[i][i + d] = true;
        }
    }

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
}

// 홀수이건 짝수이건, d가 2 이상이면
// i ~ i + d가 팰린드롬일 경우
// i + 1 ~ i + d - 1이 팰린드롬
// num[i] == num[i + d]임