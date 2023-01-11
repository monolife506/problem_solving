#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
                cout << 1 << " ";
            else
                cout << -1 << " ";
        }

        cout << '\n';
    }
    else if (n == 3)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
                cout << n / 2 - 1 << " ";
            else
                cout << -(n / 2) << " ";
        }

        cout << '\n';
    }
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

s1 + s2 + ... + sn = s1 + s2 = s2 + s3 = s3 + s4 = ...

n = 3
2a + b = a + b

n = 5
3a + 2b = a + b
2a = -b

n = 7
4a + 3b = a + b
3a = -2b

*/