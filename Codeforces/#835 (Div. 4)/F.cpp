#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, d;
ll c, a[200000];

bool f(int k)
{
    ll sum = 0;
    for (int i = 0; i < min(n, k + 1); ++i)
        sum += a[i] * ((d - (i + 1)) / (k + 1) + 1);

    return sum >= c;
}

int parametric_search()
{
    int l = 0;
    int r = d;
    int ret = -1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ret;
}

void solve()
{
    cin >> n >> c >> d;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n, greater<ll>());
    if (a[0] * d < c)
        cout << "Impossible" << '\n';
    else if (accumulate(a, a + min(n, d), 0LL) >= c)
        cout << "Infinity" << '\n';
    else
        cout << parametric_search() << '\n';
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

/*

x >= 0
(i + 1) + (k + 1)x <= d
(k + 1)x <= d - (i + 1)

x <= (d - (i + 1)) / (k + 1)

k = 5

i = 0: 1, 7, ...
i = 1: 2, 8, ...
i = 2: 3, 9, ...


*/