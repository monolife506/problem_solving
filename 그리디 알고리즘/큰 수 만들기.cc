#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<pair<ll, string>> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i].first;
        nums[i].second = to_string(nums[i].first);
    }

    sort(nums.begin(), nums.end(),
         [&](pair<ll, string> &lhs, pair<ll, string> &rhs)
         {
             if (lhs.second.length() == rhs.second.length())
                 return lhs.first > rhs.first;

             string a = lhs.second + rhs.second;
             string b = rhs.second + lhs.second;
             for (int i = 0; i < a.length(); ++i)
             {
                 if (a[i] != b[i])
                     return a[i] > b[i];
             }

             return a > b;
         });

    string ans = "";
    for (int i = 0; i < n; ++i)
        ans += nums[i].second;

    if (ans[0] != '0')
        cout << ans << '\n';
    else
        cout << 0 << '\n';
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

    solve();
}