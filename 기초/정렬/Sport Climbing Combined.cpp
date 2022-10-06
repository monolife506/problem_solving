#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Standings
{
    int b, p, q, r;
    Standings(int b = 0, int p = 0, int q = 0, int r = 0)
        : b(b), p(p), q(q), r(r) {}

    bool operator<(const Standings &rhs)
    {
        if (p * q * r != rhs.p * rhs.q * rhs.r)
            return p * q * r < rhs.p * rhs.q * rhs.r;
        else if (p + q + r != rhs.p + rhs.q + rhs.r)
            return p + q + r < rhs.p + rhs.q + rhs.r;
        else
            return b < rhs.b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Standings> v(n);
    for (Standings &s : v)
        cin >> s.b >> s.p >> s.q >> s.r;

    sort(v.begin(), v.end());
    cout << v[0].b << " " << v[1].b << " " << v[2].b << '\n';
}