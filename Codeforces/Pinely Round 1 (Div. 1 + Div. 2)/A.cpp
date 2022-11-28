#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b <= n - 2)
        cout << "Yes" << '\n';
    else if (a == n && b == n)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
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

2

1 2

3 1 1

1 3 2

*/