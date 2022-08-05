#include <iostream>
using namespace std;

const int MOD = 1000000;

int cache[3][4][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cache[0][0][1] = 1; // 출석
    cache[1][0][1] = 1; // 지각
    cache[0][1][1] = 1; // 결석
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j <= 1; ++j)
        {
            for (int k = 0; k <= 2; ++k)
            {
                cache[j][0][i + 1] += cache[j][k][i];
                cache[j][0][i + 1] %= MOD;
                cache[j + 1][0][i + 1] += cache[j][k][i];
                cache[j + 1][0][i + 1] %= MOD;
                cache[j][k + 1][i + 1] += cache[j][k][i];
                cache[j][k + 1][i + 1] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 1; ++j)
    {
        for (int k = 0; k <= 2; ++k)
        {
            ans += cache[j][k][N];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}