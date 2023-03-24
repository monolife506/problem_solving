#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int x = (n - 3) / 3;
    cout << min(x - 1, (n - 3) - (2 * x + 1)) << '\n';
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

n - 3

6 -> 3
1 1 1

10 -> 7
1 2 4

1033
1 x y

1, x, (n - 3) - (x + 1)
min(x - 1, (n - 3) - (2x + 1))

x - 1 = (n - 3) - (2x + 1)

3x = n - 3

7 / 3 = 2

1 <= x < n - 4

*/