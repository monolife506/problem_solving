#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int min_idx = min_element(a.begin(), a.end()) - a.begin();
    int max_idx = max_element(a.begin(), a.end()) - a.begin();

    if (a[min_idx] == a[max_idx])
    {
        cout << 0 << '\n';
        return;
    }
    if (a[min_idx] == 1)
    {
        cout << -1 << '\n';
        return;
    }

    vector<pii> ans;
    do
    {
        a[max_idx] = (a[max_idx] + a[min_idx] - 1) / a[min_idx];
        ans.push_back({max_idx, min_idx});
        min_idx = min_element(a.begin(), a.end()) - a.begin();
        max_idx = max_element(a.begin(), a.end()) - a.begin();
    } while (a[min_idx] != a[max_idx]);

    cout << ans.size() << '\n';
    for (auto [i, j] : ans)
        cout << i + 1 << " " << j + 1 << '\n';
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

9 20
9 3
3 3


*/