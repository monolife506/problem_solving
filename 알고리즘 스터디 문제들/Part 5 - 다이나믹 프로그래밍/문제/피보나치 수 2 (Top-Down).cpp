#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[91]; // dp[i] = i번째 피보나치 수

ll f(int cur)
{
    // Base Case
    if (cur == 0)
        return 0;
    if (cur == 1)
        return 1;

    // 이미 계산한 값임
    if (dp[cur] != -1)
        return dp[cur];

    // 값을 계산하고 return
    return dp[cur] = f(cur - 1) + f(cur - 2);
}

int main()
{
    // dp 배열을 -1로 초기화시킨다.
    // dp[i] = -1이면 그 결과가 저장되지 않았다는 의미이다.
    fill_n(&dp[0], 91, -1);

    int n;
    cin >> n;

    cout << f(n) << '\n';
}