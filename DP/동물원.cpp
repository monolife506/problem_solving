#include <iostream>
using namespace std;

const int MOD = 9901;
int cache[3][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cache[0][1] = cache[1][1] = cache[2][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        cache[0][i] = (cache[0][i - 1] + cache[1][i - 1] + cache[2][i - 1]) % MOD;
        cache[1][i] = (cache[0][i - 1] + cache[2][i - 1]) % MOD;
        cache[2][i] = (cache[0][i - 1] + cache[1][i - 1]) % MOD;
    }

    cout << (cache[0][N] + cache[1][N] + cache[2][N]) % MOD << '\n';
}