#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

// Extended Euclidean Algorithm: as + bt = gcd(a, b)
// first == gcd(a, b), second = {s, t}
pair<int, P> EEA(int a, int b)
{
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    while (r2 > 0)
    {
        int q = r1 / r2;
        int r = r1 - q * r2;
        int s = s1 - q * s2;
        int t = t1 - q * t2;

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }

    return {r1, {s1, t1}};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int K, C;
        cin >> K >> C;

        pair<int, P> ans = EEA(K, C);
        if (ans.first != 1)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
        else
        {
            ll s = ans.second.first;
            ll t = ans.second.second;
            while (C * t < K + 1)
                t += K;

            if (t > 1'000'000'000)
            {
                cout << "IMPOSSIBLE" << '\n';
            }
            else
            {
                cout << t << '\n';
            }
        }
    }
}

/*

Kx + Cy = 1

*/