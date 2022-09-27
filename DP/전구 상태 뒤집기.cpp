#include <iostream>
using namespace std;

int a[200000], dp[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        int b;
        cin >> b;
        if (b == 1)
        {
            sum += a[i];
            a[i] = -a[i];
        }
    }

    dp[0] = a[0];
    int max_diff = dp[0];
    for (int i = 1; i < N; ++i)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        max_diff = max(max_diff, dp[i]);
    }

    cout << sum + max_diff << '\n';
}