#include <iostream>
using namespace std;

int main()
{
    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;

    int ans = 0;
    for (int i = 0; i < P; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (x < X && (X - x) * (X - x) + ((Y + (H / 2)) - y) * ((Y + (H / 2)) - y) <= (H / 2) * (H / 2))
            ++ans;
        else if (X <= x && x <= X + W && Y <= y && y <= Y + H)
            ++ans;
        else if (((X + W) - x) * ((X + W) - x) + ((Y + (H / 2)) - y) * ((Y + (H / 2)) - y) <= (H / 2) * (H / 2)) // X + W < x
            ++ans;
    }

    cout << ans << '\n';
}