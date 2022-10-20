#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C[10][10];

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << C[10 - n][2] * C[4][2] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 9; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}