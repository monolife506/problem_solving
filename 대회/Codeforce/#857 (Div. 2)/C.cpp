#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    int k = 1;
    while (k < m)
        k *= 2;

    cout << n * m << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << i * k + j << " ";
        cout << '\n';
    }
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



0 1 2 3
8 9 10 11
16 17 18 19
24 25 26 27

0 1
100 101

10100 10101
11100 11101

*/