#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
double x[100000], t[100000];

double f(double x0)
{
    double ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(abs(x[i] - x0) + t[i], ans);
    return ans;
}

double ternary_search()
{
    double l = 0, r = 1e8;
    for (int i = 0; i < 100; ++i)
    {
        double p = (l * 2 + r) / 3;
        double q = (l + r * 2) / 3;
        if (f(p) > f(q))
            l = p;
        else
            r = q;
    }

    return l;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    cout << fixed << setprecision(6) << ternary_search() << '\n';
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