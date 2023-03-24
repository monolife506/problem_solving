#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> nums(31, 1);
    for (int i = 1; i <= 30; ++i)
        nums[i] = nums[i - 1] * 2;

    vector<pll> ans;
    for (int i = 0; i < n; ++i)
    {
        if (!binary_search(nums.begin(), nums.end(), a[i]))
            ans.push_back({i + 1, *lower_bound(nums.begin(), nums.end(), a[i]) - a[i]});
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
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