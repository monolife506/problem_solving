#include <iostream>
using namespace std;
typedef long long ll;

ll p[500001], cache[2][3][500002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> p[i];
        cache[0][0][i] = cache[0][0][i - 1] + p[i];
        cache[0][1][i] = max(cache[0][1][i - 1], cache[0][2][i - 1]) + p[i];
        cache[0][2][i] = max(cache[0][0][i] + p[i], cache[0][2][i - 1] + 2 * p[i]);
    }

    for (size_t i = N; i > 0; i--)
    {
        cache[1][0][i] = cache[1][0][i + 1] + p[i];
        cache[1][1][i] = max(cache[1][1][i + 1], cache[1][2][i + 1]) + p[i];
        cache[1][2][i] = max(cache[1][0][i] + p[i], cache[1][2][i + 1] + 2 * p[i]);
    }

    ll ans = INT64_MIN;
    for (size_t i = 1; i <= N; i++)
    {
        ll l = max(cache[0][1][i], cache[0][2][i]);
        ll r = max(cache[1][1][i + 1], cache[1][2][i + 1]);
        ans = max(ans, l + r);
    }

    cout << ans << '\n';
}

/*

111111
111111
000000

1110000
0111111
0000111

111000
011111
000111

*/