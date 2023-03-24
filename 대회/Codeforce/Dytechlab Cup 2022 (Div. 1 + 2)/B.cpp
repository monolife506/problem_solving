#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_min_square(ll l, ll r)
{
    ll lo = 1;
    ll hi = 1e9;
    ll mid;
    ll ret = -1;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (mid * mid > r)
            hi = mid - 1;
        else if (mid * mid < l)
            lo = mid + 1;
        else
        {
            ret = mid;
            hi = mid - 1;
        }
    }

    return ret;
}

ll get_max_square(ll l, ll r)
{
    ll lo = 1;
    ll hi = 1e9;
    ll mid;
    ll ret = -1;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (mid * mid > r)
            hi = mid - 1;
        else if (mid * mid < l)
            lo = mid + 1;
        else
        {
            ret = mid;
            lo = mid + 1;
        }
    }

    return ret;
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll min_square = get_min_square(l, r);
    ll max_square = get_max_square(l, r);

    ll ans = 0;
    if (min_square != -1 && max_square != -1)
    {
        ans = (max_square - min_square) * 3;
        if (min_square * min_square > l)
            ans += ((min_square * min_square - 1) - l) / (min_square - 1) + 1;
        ans += (r - max_square * max_square) / max_square + 1;
    }
    else
    {
        ll x = sqrt(r);
        if (x * x + x >= l && x * x + x <= r)
            ++ans;
        if (x * x + x * 2 >= l && x * x + x * 2 <= r)
            ++ans;
    }

    cout << ans << '\n';
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

1 2 3
4 5 6 7 8
9 10 11 12 13 14 15
16 17 18 19 20 21 22 23 24



*/