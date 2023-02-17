#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll a, b, n, m;
    cin >> a >> b >> n >> m;

    if (a <= b)
    {
        cout << a * m * (n / (m + 1)) + a * (n % (m + 1)) << '\n';
    }
    else if (a * m <= b * (m + 1))
    {
        cout << a * m * (n / (m + 1)) + b * (n % (m + 1)) << '\n';
    }
    else
    {
        cout << b * n << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}