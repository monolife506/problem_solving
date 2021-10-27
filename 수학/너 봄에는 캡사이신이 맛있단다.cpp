#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1'000'000'007;

int scovile[300001];
int power2[300001];

void preprocess(int N)
{
    power2[0] = 1;
    for (size_t i = 1; i < N; i++)
        power2[i] = (power2[i - 1] * 2) % MOD;

    sort(scovile, scovile + N, greater<int>());
}

ll calculate(int N)
{
    ll ans = 0;
    for (size_t i = 0; i < N; i++) {
        ll tmp1 = (power2[N - (i + 1)] - power2[i] + MOD) % MOD;
        ll tmp2 = (tmp1 * (scovile[i] % MOD)) % MOD;
        ans += tmp2;
        ans %= MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> scovile[i];

    preprocess(N);
    cout << calculate(N) << '\n';
}

/*

N개의 음식
2 ~ N개

    10 6 5 5 4 1
(+)  5 4 3 2 1 0
(-)  0 1 2 3 4 5

2^4 * (10 - 1)
2^3 * (10 - 4 + 6 - 1)
2^2 * (10 - 5 + 6 - 4 + 5 - 1)
2^1 * (10 - 5 + 6 - 5 + 5 - 4 + 5 - 1)
2^0 * (10 - 6 + 6 - 5 + 5 - 5 + 5 - 4 + 4 - 1)

*/