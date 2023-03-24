#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998'244'353;

int c[20][20];

void solve()
{
    int l, r;
    cin >> l >> r;

    int n = 0;
    for (int i = l; i <= r; i *= 2)
        n++;

    ll m = 0;
    for (int i = 0; i < n; ++i)
    {
        int num = (int)pow(2, (n - 1) - i) * (int)pow(3, i);
        if (l * num > r)
            break;

        m += ((r / num) - l + 1) * c[n - 1][i];
        m %= MOD;
    }

    cout << n << " " << m << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    c[0][0] = 1;
    for (int i = 1; i < 20; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

n <= 20

4 8 16 32 64
5 10 20 40 80
6 12 24 48 96
4 12 24 48 96
4 8 24 48 96
4 8 16 48 96
4 8 16 32 96

k * 2^4 <= r

k <= r / 2^4

*/