#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    vector<bool> flag(n + 1, false);
    flag[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (i + b[i] <= n && flag[i - 1])
            flag[i + b[i]] = true;
        if (i - b[i] > 0 && flag[i - b[i] - 1])
            flag[i] = true;
    }

    cout << (flag[n] ? "YES" : "NO") << '\n';
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