#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    ll x, y;
    cin >> x >> y;

    vector<int> ans;
    for (int i = y; i < x; ++i)
        ans.push_back(i);
    for (int i = x; i > y; --i)
        ans.push_back(i);

    cout << ans.size() << '\n';
    for (int num : ans)
        cout << num << " ";
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

/*

0 1 0 1 0 1 0 -1 0 -1
0 1 0 1 0 1 0 1 0 -1 0 -1 0 -1 0 -1

3 2 1 0 -1 -2 -1 0 1 2

-3 -1

-3 -2 -1

*/