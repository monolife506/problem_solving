#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll product = 1;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        product *= a;
    }

    cout << (product + (n - 1)) * 2022 << '\n';
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