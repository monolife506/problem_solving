#include <iostream>
using namespace std;

const int MOD = 10007;

int N, cache[10][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i <= 9; ++i)
        cache[i][1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                cache[j][i] += cache[k][i - 1];
                cache[j][i] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; ++i)
    {
        ans += cache[i][N];
        ans %= MOD;
    }

    cout << ans << '\n';
}