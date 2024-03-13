#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    for (int i = 1; i < n - 1; ++i)
    {
        a[i] -= a[i - 1] * 2;
        a[i + 1] -= a[i - 1];
        a[i - 1] = 0;

        if (a[i] < 0 || a[i + 1] < 0)
        {
            cout << "NO" << '\n';
            return;
        }

        if (i == n - 2 && (a[i] != 0 || a[i + 1] != 0))
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

1 4 5 2
1 2 1 0


0 0 6 2

*/