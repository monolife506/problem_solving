#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int y, m;
        cin >> y >> m;

        if (m == 1)
            cout << y - 1 << " " << 12 << " " << 31 << '\n';
        else if (m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11)
            cout << y << " " << m - 1 << " " << 31 << '\n';
        else if (m == 5 || m == 7 || m == 10 || m == 12)
            cout << y << " " << m - 1 << " " << 30 << '\n';
        else // m == 2
        {
            if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0))
                cout << y << " " << 2 << " " << 29 << '\n';
            else
                cout << y << " " << 2 << " " << 28 << '\n';
        }
    }
}