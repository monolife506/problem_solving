#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void solve()
{
    ull n, x;
    cin >> n >> x;

    if (n < x)
    {
        cout << -1 << '\n';
        return;
    }
    else if (n == x)
    {
        cout << n << '\n';
        return;
    }
    else
    {
        bitset<64> b(n);
        for (int i = 0; i < 63; ++i)
        {
            if (b[i] == 1 && b[i + 1] == 0)
            {
                for (int j = i; j >= 0; --j)
                    b[j] = 0;

                ull cur = b.to_ullong();
                if (cur == x)
                {
                    cout << (cur | (1ULL << (i + 1))) << '\n';
                    return;
                }
            }
        }

        cout << -1 << '\n';
        return;
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

110011
110100
1000000

101010
101100 (101000)
110000 (100000)


*/