#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;

bool f(int kth, vector<int> &a, vector<pii> &v)
{
    if (m >= a[n - kth])
    {
        int cnt = 1;
        int cur_m = m - a[n - kth];
        for (int i = 0; i < n; ++i)
        {
            if (v[i].second == n - kth)
                continue;
            if (cur_m < v[i].first)
                break;

            cur_m -= v[i].first;
            cnt++;
        }

        if (cnt >= n - kth)
            return true;
    }

    int cnt = 0;
    int cur_m = m;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].second == n - kth)
            continue;
        if (cur_m < v[i].first)
            break;

        cur_m -= v[i].first;
        cnt++;
    }

    if (cnt >= n - kth + 1)
        return true;

    return false;
}

int parametric_search(vector<int> &a, vector<pii> &v)
{
    int l = 1;
    int r = n;
    int mid;
    int ret = n + 1;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid, a, v))
        {
            r = mid - 1;
            ret = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

void solve()
{
    cin >> n >> m;

    vector<int> a(n);
    vector<pii> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v[i] = {a[i], i};
    }

    sort(v.begin(), v.end());

    cout << parametric_search(a, v) << '\n';
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

k (1 <= k <= n)등이 가능한가?

if win (n - k)th
m = m - a[n - k]
needs

1 2 3 4

*/