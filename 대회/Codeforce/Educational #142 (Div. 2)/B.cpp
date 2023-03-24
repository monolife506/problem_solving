#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    if (a1 > 0)
    {
        int ans = 0, m1 = 0, m2 = 0;

        ans += a1;
        m1 += a1;
        m2 += a1;

        ans += min(a2, a3) * 2;

        int tmp = min(a2, a3);
        a2 -= tmp;
        a3 -= tmp;

        if (a2 != 0)
        {
            if (m2 > a2)
                ans += a2;
            else if (m2 == a2)
                ans += m2;
            else
                ans += m2 + 1;

            m2 -= a2;
        }
        else if (a3 != 0)
        {
            if (m1 > a3)
                ans += a3;
            else if (m1 == a3)
                ans += m1;
            else
                ans += m1 + 1;

            m1 -= a3;
        }

        if (m1 >= 0 && m2 >= 0 && a4 >= 0)
        {
            if (min(m1, m2) > a4)
                ans += a4;
            else if (min(m1, m2) == a4)
                ans += min(m1, m2);
            else
                ans += min(m1, m2) + 1;
        }

        cout << ans << '\n';
    }
    else
    {
        cout << 1 << '\n';
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

1 1 1 0


*/