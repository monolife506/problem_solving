#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        if (s / k < b)
        {
            cout << -1 << '\n';
        }
        else if ((s - (n - 1) * (k - 1)) / k > b)
        {
            cout << -1 << '\n';
        }
        else
        {
            ll an = s;
            int m = 0;
            while ((s - m * (k - 1)) / k != b)
            {
                ++m;
            }

            for (int i = 0; i < (n - 1) - m; ++i)
                cout << 0 << " ";
            for (int i = 0; i < m; ++i)
                cout << k - 1 << " ";

            cout << s - m * (k - 1) << '\n';
        }
    }
}

/*

a1 / k + a2 / k + ... + an / k = b
a1 + a2 + ... + an = s

100 / 6 < 16
s / k

(s - m * (k - 1)) / k == b

*/