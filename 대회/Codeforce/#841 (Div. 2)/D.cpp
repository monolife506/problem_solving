#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;

vector<int> find_range_min(int l, vector<int> &arr)
{
    vector<int> ret;

    deque<pii> dq;
    for (int i = 0; i < arr.size(); ++i)
    {
        while (!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();

        dq.push_back({arr[i], i});

        while (dq.front().second <= i - l)
            dq.pop_front();

        if (i >= l - 1)
            ret.push_back(dq.front().first);
    }

    return ret;
}

bool f(int l, vector<vector<int>> &a)
{
    vector<vector<int>> min_row(n);
    for (int i = 0; i < n; ++i)
        min_row[i] = find_range_min(l, a[i]);

    for (int i = 0; i < m - (l - 1); ++i)
    {
        vector<int> tmp(n);
        for (int j = 0; j < n; ++j)
            tmp[j] = min_row[j][i];

        vector<int> min_col = find_range_min(l, tmp);
        for (int min_val : min_col)
        {
            if (min_val >= l)
                return true;
        }
    }

    return false;
}

int parametric_search(vector<vector<int>> &a)
{
    int l = 1;
    int r = min(n, m);
    int mid;
    int ret = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid, a))
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
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    cout << parametric_search(a) << '\n';
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

https://codeforces.com/blog/entry/53810

*/