#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double x, y, d, t;
    while (cin >> x >> y >> d >> t)
    {
        double dist = sqrt(x * x + y * y);
        double ans = dist;

        if (d > t)
        {
            int cnt = (int)(dist / d);
            ans = min(ans, (t * cnt) + abs((dist - d * cnt)));

            if (cnt == 0)
            {
                ans = min(ans, t * (cnt + 1) + abs(dist - d * (cnt + 1)));
                ans = min(ans, t * (cnt + 2));
            }
            else
            {
                ans = min(ans, t * (cnt + 1));
            }
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }
}

/*

T -> D
2T -> 0 ~ 2D
3T -> D ~ 3D
4T -> 0 ~ 4D
5T -> D ~ 5D
...
(n % 2 == 0), nT: 0 ~ nD
(n % 2 == 1), nT: D ~ nD

*/