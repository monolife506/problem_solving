#include <iostream>
using namespace std;

const int MOD = 10007;

int cache[53][53];

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    if (cache[n][r] != 0)
        return cache[n][r];

    return cache[n][r] = cache[n][n - r] = (combination(n - 1, r - 1) + combination(n - 1, r)) % MOD;
}

int fourcard(int n)
{
    int ret = 0;
    int tmp;

    for (size_t i = 1; 4 * i <= n; i++) {
        if (i % 2 == 1) {
            tmp = (combination(13, i) * combination(52 - 4 * i, n - 4 * i)) % MOD;
            ret = (ret + tmp) % MOD;
        } else {
            tmp = (combination(13, i) * combination(52 - 4 * i, n - 4 * i)) % MOD;
            ret = (ret - tmp + MOD) % MOD;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    cout << fourcard(N) << '\n';
}

/*

포함 배제의 원리: 이산수학 까먹지 말자

*/