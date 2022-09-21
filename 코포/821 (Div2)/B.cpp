#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        int n, x, y;
        cin >> n >> x >> y;

        if (x > y)
            swap(x, y);

        if (x != 0 || y == 0 || (n - 1) % y != 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            int nth = y, winner;
            for (int i = 1; i <= n - 1; ++i)
            {
                if (nth == y)
                {
                    winner = i + 1;
                    nth = 0;
                }

                cout << winner << " ";
                ++nth;
            }

            cout << '\n';
        }
    }
}

/*

1 2 3 4 5

1 2
2 3
3 4


*/