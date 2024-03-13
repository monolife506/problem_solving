#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);

    ll total = 0;
    for (auto &ai : a)
    {
        cin >> ai;
        total += ai;
    }

    ll target = total / n;
    ll remain = 0;
    for (auto &ai : a)
    {
        if (ai < target)
        {
            if (remain < target - ai)
            {
                cout << "NO" << '\n';
                return;
            }
            else
            {
                remain -= target - ai;
            }
        }
        else
        {
            remain += ai - target;
        }
    }

    cout << "YES" << '\n';
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