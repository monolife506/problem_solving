#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;

    ll total = 0, odd_cnt = 0, even_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            ++even_cnt;
        else
            ++odd_cnt;

        total += a;
    }

    for (int i = 0; i < q; ++i)
    {
        int type, x;
        cin >> type >> x;
        if (x % 2 == 0)
        {
            if (type == 0)
                total += even_cnt * x;
            else
                total += odd_cnt * x;
        }
        else
        {
            if (type == 0)
            {
                total += even_cnt * x;
                odd_cnt += even_cnt;
                even_cnt = 0;
            }
            else
            {
                total += odd_cnt * x;
                even_cnt += odd_cnt;
                odd_cnt = 0;
            }
        }

        cout << total << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*


*/