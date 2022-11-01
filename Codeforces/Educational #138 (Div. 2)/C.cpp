#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100];

bool f(int k)
{
    vector<int> nums, tmp;
    for (int i = 0; i < n; ++i)
        nums.push_back(a[i]);

    sort(nums.begin(), nums.end());
    for (int i = 1; i <= k; ++i)
    {
        auto it = upper_bound(nums.begin(), nums.end(), k - i + 1);
        if (it == nums.begin())
            return false;

        nums.erase(it - 1);
        *nums.begin() += k - i + 1;

        sort(nums.begin(), nums.end());
    }

    return true;
}

int parametric_search()
{
    int l = 0;
    int r = n;
    int ret;

    while (l <= r)
    {
        int mid = (l + r) / 2;
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
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << parametric_search() << '\n';
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

3
1 1 2

k, k - 1, k - 2, ...

4
4 4 4 4

1
1

5
1 3 2 1 1


1
9
1 4 3 1 1 2 3 5 3

3

*/