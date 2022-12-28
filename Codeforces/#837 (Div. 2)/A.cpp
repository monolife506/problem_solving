#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    ll min_cnt = 0;
    ll max_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == min_a)
            min_cnt++;
        if (a[i] == max_a)
            max_cnt++;
    }

    if (min_a == max_a)
        cout << max_cnt * (max_cnt - 1) << '\n';
    else
        cout << max_cnt * min_cnt * 2 << '\n';
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