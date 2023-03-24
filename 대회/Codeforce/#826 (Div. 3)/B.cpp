#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    if (n == 3)
    {
        cout << -1;
    }
    else
    {
        for (int i = n / 2 + 1; i <= n; ++i)
            cout << i << " ";
        for (int i = n / 2; i > 0; --i)
            cout << i << " ";
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

5
3 4 5 1 2

7
4 5 6 7 1 2 3


*/