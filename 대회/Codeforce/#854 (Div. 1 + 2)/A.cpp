#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for (int i = 0; i < m; ++i)
        cin >> p[i];

    set<int> nums;
    vector<int> ans(n, -1);
    int idx = n - 1;
    for (int i = 0; i < m; ++i)
    {
        if (nums.find(p[i]) == nums.end())
        {
            nums.insert(p[i]);
            if (idx >= 0)
                ans[idx--] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    cout << '\n';
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