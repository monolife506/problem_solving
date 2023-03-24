#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll tmp = n, two = 0, five = 0;
    while (tmp % 2 == 0)
    {
        ++two;
        tmp /= 2;
    }
    while (tmp % 5 == 0)
    {
        ++five;
        tmp /= 5;
    }

    ll k = 1;
    if (two < five)
    {
        while (two != five)
        {
            if (k * 2 > m)
                break;

            ++two;
            k *= 2;
        }
    }
    else if (two > five)
    {
        while (two != five)
        {
            if (k * 5 > m)
                break;

            ++five;
            k *= 5;
        }
    }

    while (true)
    {
        if (k * 10 > m)
            break;

        k *= 10;
    }

    cout << 1LL * n * (m - (m % k)) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*


6: 5 -> 50 -> 500 -> ...
25: 2 -> 4 -> 40 -> 400 ->


*/