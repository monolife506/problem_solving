#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (a * 2 > b)
    {
        if (n % 2 == 0)
            cout << (n / 2) * b << '\n';
        else
            cout << (n / 2) * b + a << '\n';
    }
    else
    {
        cout << n * a << '\n';
    }
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

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}