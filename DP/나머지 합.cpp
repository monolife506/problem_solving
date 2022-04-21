#include <iostream>
using namespace std;
typedef long long ll;

int psum[1000001], cnt[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] = (psum[i] % M + psum[i - 1] % M) % M;
        ++cnt[psum[i]];
    }

    ll ans = cnt[0];
    for (size_t i = 0; i < M; ++i)
        ans += (1LL * cnt[i] * (cnt[i] - 1)) / 2;

    cout << ans << '\n';
}

/*

0 3
1 2
2 0

*/