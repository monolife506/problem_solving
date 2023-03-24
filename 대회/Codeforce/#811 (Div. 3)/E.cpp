#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            a[i] += a[i] % 10;
    }

    int max_a = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 10 != 0)
            break;
        if (a[i] != max_a)
            break;

        if (i == n - 1)
        {
            cout << "Yes" << '\n';
            return;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 10 == 0)
            break;

        if (a[i] % 10 == 2 || a[i] % 10 == 4 || a[i] % 10 == 8)
        {
            if (max_a % 10 == 2 || max_a % 10 == 4 || max_a % 10 == 8)
            {
                if (((max_a / 10) - (a[i] / 10)) % 2 == 1)
                    break;
            }
            else
            {
                if (((max_a / 10) - (a[i] / 10)) % 2 == 0)
                    break;
            }
        }
        else
        {
            if (max_a % 10 == 2 || max_a % 10 == 4 || max_a % 10 == 8)
            {
                if (((max_a / 10) - (a[i] / 10)) % 2 == 0)
                    break;
            }
            else
            {
                if (((max_a / 10) - (a[i] / 10)) % 2 == 1)
                    break;
            }
        }

        if (i == n - 1)
        {
            cout << "Yes" << '\n';
            return;
        }
    }

    cout << "No" << '\n';
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

0 -> ...
1 -> 2 -> 4 -> 8 -> 16 -> 22 -> ...
3 -> 6 -> 12 -> 14 -> 18 -> ...
5 -> 10 -> ...
7 -> 14 -> 18 -> ...
9 -> 18 -> ...

2 4 8
16
22 24 28
36
42


1002 ?

*/