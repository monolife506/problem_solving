#include <iostream>
using namespace std;

int main()
{
    int a, b, n, w, x, y;
    cin >> a >> b >> n >> w;

    if (a == b)
    {
        if (n != 2 || b * n != w)
        {
            cout << -1;
            return 0;
        }

        x = y = 1;
    }
    else
    {
        if (abs(b * n - w) % abs(b - a) != 0)
        {
            cout << -1;
            return 0;
        }

        x = (b * n - w) / (b - a);
        y = n - x;
    }

    if (x < 1 || y < 1)
    {
        cout << -1;
        return 0;
    }

    cout << x << " " << y;
}

// bx + by = bn
// ax + by = w

// 3x + 3y = 24
// 3x + 4y = 32

// x + y = 2
// 100x + 100y = 200