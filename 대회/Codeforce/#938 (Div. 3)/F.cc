#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cache[201][201][201];

int dp(int a, int b, int c)
{
    if (cache[a][b][c] != -1)
        return cache[a][b][c];

    if (a + b + c == 0)
        return cache[a][b][c] = 0;

    int &ret = cache[a][b][c] = 0;
    if (a > 0)
        ret = max(ret, dp(a - 1, b, c));
    if (b > 0)
        ret = max(ret, dp(a, b - 1, c));
    if (c > 0)
        ret = max(ret, dp(a, b, c - 1));
    if ((a + c) % 2 == 0 && (b + c) % 2 == 0)
        ret++;

    return ret;
}

void solve()
{
    int p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;

    int val = dp(p1, p2, p3);
    cout << val + p4 / 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    memset(cache, -1, sizeof(cache));

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

 01
 10
 11
100

*/