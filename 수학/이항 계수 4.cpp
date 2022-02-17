#include <iostream>
using namespace std;
typedef long long ll;

int M, fac[2001];

int pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % M;

    int half = pow(a, b / 2);
    int ret = (half * half) % M;
    return (b % 2 == 0) ? ret : (ret * (a % M)) % M;
}

int combination(int n, int k)
{
    int ret = fac[n];
    ret = (ret * pow(fac[k], M - 2)) % M;
    ret = (ret * pow(fac[n - k], M - 2)) % M;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, K;
    cin >> N >> K >> M;

    fac[0] = 1;
    for (int i = 1; i <= M; ++i)
        fac[i] = (fac[i - 1] * (i % M)) % M;

    int ans = 1;
    while (N != 0)
    {
        ans *= combination(N % M, K % M);
        ans %= M;
        N /= M;
        K /= M;
    }

    cout << ans << '\n';
}

/*

1445 = 206 * 7 + 3
206 = 29 * 7 + 3
29 = 4 * 7 + 1
4
*/