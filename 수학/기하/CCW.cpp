// 11758번: CCW

#include <iostream>
#include <cmath>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    return (cross > 0) - (cross < 0);
}

int main()
{
    int x[3];
    int y[3];
    for (size_t i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    cout << ccw(x[0], y[0], x[1], y[1], x[2], y[2]);
}
