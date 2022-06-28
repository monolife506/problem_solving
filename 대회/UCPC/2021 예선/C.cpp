#include <iostream>
#include <iomanip>
using namespace std;

double cache[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double a, k;
    cin >> a >> cache[1] >> k;
    cache[1] /= 100;
    k = 1 + (k / 100);

    int cnt = 2;
    while (true)
    {
        cache[cnt] = cache[cnt - 1] * k;
        if (cache[cnt] >= 1)
        {
            cache[cnt] = 1;
            break;
        }

        ++cnt;
    }

    double ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        double e = 1;
        for (int j = 1; j < i; j++)
        {
            e *= (1.0 - cache[j]);
        }

        e *= cache[i] * (a * i);
        ans += e;
    }

    cout << fixed << setprecision(7) << ans << '\n';
}

/*

a, a
d, d + k, d + 2k,

50% -> 75% -> 100%

0.5 * a
0.5 * (0.5 * 1.5) * 2a
0.5 * (1 - (0.5 * 1.5)) * 3a

*/