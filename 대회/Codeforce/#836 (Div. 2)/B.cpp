#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 1)
    {
        for (int i = 0; i < n; ++i)
            cout << 1 << " ";
    }
    else
    {
        cout << 1 << " " << 3 << " ";
        for (int i = 0; i < n - 2; ++i)
            cout << 2 << " ";
    }

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

k(n - 2) + a + 1 = (a + 1) * n

k (n - 2) = (n - 1) * (a + 1)

k = (n - 1) * (a + 1) / (n - 2)

*/