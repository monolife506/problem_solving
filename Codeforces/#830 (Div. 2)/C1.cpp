#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int L, R;
    cin >> L >> R;

    ll sum = 0;
    int mask = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        mask ^= a[i];
    }

    ll target = sum - mask;
    sum = a[1];
    mask = a[1];

    int l = 1, r = 1;
    int ans_l = 1, ans_r = n;
    while (l <= r)
    {
        if (sum - mask == target)
        {
            if (r - l < ans_r - ans_l)
            {
                ans_l = l;
                ans_r = r;
            }

            sum -= a[l];
            mask ^= a[l];
            ++l;
        }
        else
        {
            if (r != n)
            {
                sum += a[r + 1];
                mask ^= a[r + 1];
                ++r;
            }
            else
            {
                sum -= a[l];
                mask ^= a[l];
                ++l;
            }
        }
    }

    cout << ans_l << " " << ans_r << '\n';
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

4 1
5 5 4 1
1 4

1 2

*/