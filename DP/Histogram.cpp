#include <bits/stdc++.h>
using namespace std;

const double INF = 160000000001;
double psum[2][4001], cache[31][4001];

double cost(int l, int r)
{
    double m = (psum[0][r] - psum[0][l - 1]) / (r - l + 1);
    return (psum[1][r] - psum[1][l - 1]) - 2.0 * m * (psum[0][r] - psum[0][l - 1]) + m * m * (r - l + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 31 * 4001, INF);

    int B;
    cin >> B;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> psum[0][i];
        psum[1][i] = psum[0][i] * psum[0][i];

        psum[0][i] += psum[0][i - 1];
        psum[1][i] += psum[1][i - 1];
    }

    for (int i = 1; i <= n; ++i)
        cache[1][i] = cost(1, i);

    for (int i = 2; i <= B; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            for (int k = i; k <= j; ++k)
                cache[i][j] = min(cache[i][j], cache[i - 1][k - 1] + cost(k, j));
        }
    }

    double ans = INF;
    for (int i = 1; i <= B; ++i)
        ans = min(ans, cache[i][n]);

    cout << fixed << setprecision(6) << ans << '\n';
}

/*

(x - m)^2 = x^2 - 2xm + m^2

[l, r]

m = (f[l] + f[l + 1] + ... + f[r]) / (r - l + 1)

(f[l]^2 + f[l + 1]^2 + ... + f[r]^2)
-2m(f[l] + f[l + 1] + ... + f[r])
+ (r - l + 1) * m^2

*/