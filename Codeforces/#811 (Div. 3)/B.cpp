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

    vector<bool> flag(n + 1, false);
    for (int i = n - 1; i >= 0; --i)
    {
        if (!flag[a[i]])
        {
            flag[a[i]] = true;
        }
        else
        {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << 0 << '\n';
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