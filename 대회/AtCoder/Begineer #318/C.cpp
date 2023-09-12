#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D, P;
    cin >> N >> D >> P;

    vector<ll> F(N);
    for (int i = 0; i < N; ++i)
        cin >> F[i];

    sort(F.begin(), F.end(), greater<ll>());
    vector<ll> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i)
        psum[i] = psum[i - 1] + F[i - 1];

    ll ans = 0;
    int cur = 0;
    while (cur < N)
    {
        if (cur + D > N)
        {
            if (psum[N] - psum[cur] > P)
            {
                ans += P;
                cur += D;
            }
            else
            {
                ans += F[cur++];
            }
        }
        else
        {
            if (psum[cur + D] - psum[cur] > P)
            {
                ans += P;
                cur += D;
            }
            else
            {
                ans += F[cur++];
            }
        }
    }

    cout << ans << '\n';
}