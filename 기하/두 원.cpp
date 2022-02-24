#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double ans;

    if (r1 + r2 <= d)
        ans = 0;
    else if (abs(r1 - r2) >= d)
        ans = M_PI * min(r1, r2) * min(r1, r2);
    else
    {
        double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

        double s1 = (r1 * r1 * 2 * theta1) / 2 - (r1 * r1 * sin(2 * theta1)) / 2;
        double s2 = (r2 * r2 * 2 * theta2) / 2 - (r2 * r2 * sin(2 * theta2)) / 2;
        ans = s1 + s2;
    }

    cout << fixed << setprecision(3) << ans << '\n';
}

/*

접하거나 만나지 않는 경우: (r1 + r2)^2 >= (x1 - x2)^2 + (y1 - y2)^2
교차하는 경우:
내부에 있는 경우:

*/