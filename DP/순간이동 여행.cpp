#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll cache[3001]; // cache[i]: 높이가 i인 포화 이진 트리를 순회하는 교차하지 않는 최소 경로의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    cache[1] = cache[2] = 1;
    for (int i = 3; i < N; ++i)
    {
        cache[i] = 1;
        for (int j = 1; j <= i - 2; ++j)
        {
            cache[i] += (cache[j] * 2) % MOD;
            cache[i] %= MOD;
        }
    }

    ll ans = (K != 1) ? (cache[N - K] * 2) % MOD : cache[N - 1];
    for (int i = N - K + 1; i <= N - 2; ++i) // left side
    {
        ans += cache[i];
        ans %= MOD;
    }
    for (int i = N - 2; i >= 1; --i) // right side
    {
        ans += cache[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

/*

1 - 1
1 1 - 1
2 - 1

1 2 - 2 1
1 1 2 - 2 1
2 2 - 2 1
3 - 2 1

1 2 3 - 3 2 1
1 1 2 3 - 3 2 1
2 2 3 - 3 2 1
3 3 - 3 2 1
4 - 3 2 1

*/