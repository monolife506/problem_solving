#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll find_closest(ll target, vector<ll> &arr)
{
    int n = arr.size();

    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    ll l = 0;
    ll r = n - 1;
    ll mid;
    while (l < r)
    {
        mid = (l + r) / 2;

        if (arr[mid] == target)
            return arr[mid];

        if (target < arr[mid])
        {
            if (mid > 0 && target > arr[mid - 1])
            {
                if (target - arr[mid - 1] >= arr[mid] - target)
                    return arr[mid];
                else
                    return arr[mid - 1];
            }

            r = mid;
        }
        else
        {
            if (mid < n - 1 && target < arr[mid + 1])
            {
                if (target - arr[mid] >= arr[mid + 1] - target)
                    return arr[mid + 1];
                else
                    return arr[mid];
            }

            l = mid + 1;
        }
    }

    return arr[mid];
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    vector<ll> d(m);
    for (auto &di : d)
        cin >> di;

    vector<ll> f(k);
    for (auto &fi : f)
        cin >> fi;

    vector<pair<ll, int>> diff;
    for (int i = 0; i < n - 1; ++i)
        diff.push_back({a[i + 1] - a[i], i});

    sort(diff.begin(), diff.end(), greater<pair<ll, int>>());
    if (diff.size() > 1 && diff[0].first == diff[1].first)
    {
        cout << diff[0].first << '\n';
        return;
    }

    ll max_diff = diff[0].first;
    ll l = a[diff[0].second];
    ll r = a[diff[0].second + 1];
    sort(f.begin(), f.end());
    for (int i = 0; i < m; ++i)
    {
        if (d[i] >= r)
            continue;
        if (d[i] + f[0] >= r)
            continue;

        if (l % 2 == r % 2)
        {
            ll val = d[i] + find_closest((l + r) / 2 - d[i], f);
            if (val > l && val < r)
                max_diff = min(max_diff, max(val - l, r - val));
        }
        else
        {
            ll val = d[i] + find_closest((l + r) / 2 - d[i], f);
            if (val > l && val < r)
                max_diff = min(max_diff, max(val - l, r - val));

            val = d[i] + find_closest((l + r) / 2 + 1 - d[i], f);
            if (val > l && val < r)
                max_diff = min(max_diff, max(val - l, r - val));
        }
    }

    if (diff.size() >= 2)
        cout << max(max_diff, diff[1].first) << '\n';
    else
        cout << max_diff << '\n';
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

4 5 6 7

*/