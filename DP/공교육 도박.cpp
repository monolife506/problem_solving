#include <iomanip>
#include <iostream>
using namespace std;

double cache[7][7][7][1001];

int prize(int d1, int d2, int d3)
{
    if (d1 == d2 && d2 == d3)
        return 10000 + d1 * 1000;
    else if (d1 == d2)
        return 1000 + d1 * 100;
    else if (d1 == d3)
        return 1000 + d1 * 100;
    else if (d2 == d3)
        return 1000 + d2 * 100;
    else
        return max(d1, max(d2, d3)) * 100;
}

double dp(int d1, int d2, int d3, int n)
{
    if (n == 0)
        return prize(d1, d2, d3);
    if (cache[d1][d2][d3][n] != 0.0)
        return cache[d1][d2][d3][n];

    double e = 0;
    for (int d4 = 1; d4 <= 6; ++d4)
        e += dp(d2, d3, d4, n - 1) / 6;

    cache[d1][d2][d3][n] = max(dp(d1, d2, d3, n - 1), e);
    return cache[d1][d2][d3][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    double sum = 0;
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            for (int k = 1; k <= 6; ++k)
                sum += dp(i, j, k, N - 3);
        }
    }

    cout << setprecision(12) << fixed << sum / 216 << '\n';
}

/*

x y z




*/