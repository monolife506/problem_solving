#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (size_t tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            for (int i = n - 2; i > 0; --i)
                cout << i << " ";

            cout << n - 1 << " " << n << '\n';
        }
        else
        {
            cout << 1 << " " << 2 << " " << 3 << " ";
            for (int i = n - 2; i > 3; --i)
                cout << i << " ";

            cout << n - 1 << " " << n << '\n';
        }
    }
}

/*

n is even
2 - 1 | 3 4
4 - 3 | 2 - 1 | 5 6

n is odd
1 2 - 3 | 4 5
1 2 - 3 | 5 - 4 | 6 7
1 2 - 3 | 7 - 6 | 5 - 4 | 8 9

*/