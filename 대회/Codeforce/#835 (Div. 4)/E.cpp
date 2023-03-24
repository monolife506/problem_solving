#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inversion_count(vector<int> &v)
{
    ll ret = 0;
    ll cnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == 0)
            ret += cnt;
        else
            ++cnt;
    }

    return ret;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    b = a;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            break;
        }
    }

    c = a;
    for (int i = n - 1; i >= 0; --i)
    {
        if (c[i] == 1)
        {
            c[i] = 0;
            break;
        }
    }

    cout << max(inversion_count(a), max(inversion_count(b), inversion_count(c))) << '\n';
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