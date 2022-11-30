#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, x;
    cin >> n >> x;

    if (n % x != 0)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> p(n + 1, -1);
    p[1] = x;
    p[n] = 1;

    int cur = x;
    while (cur < n)
    {
        for (int m = cur * 2; m <= n; m += cur)
        {
            if (n % m == 0)
            {
                p[cur] = m;
                cur = m;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == -1)
            cout << i << " ";
        else
            cout << p[i] << " ";
    }

    cout << '\n';
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

n = 6

x = 2
2 6 3 4 5 1

x = 3
3 2 6 4 5 1


*/