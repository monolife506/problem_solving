#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    int l = 0, r = n - 1;
    bool flag = false;
    while (l != r && k > 0)
    {
        if (!flag)
        {
            if (a[l] <= a[r])
            {
                if (k < a[l] * 2 - 1)
                {
                    k = 0;
                    break;
                }

                flag = true;
                k -= a[l] * 2 - 1;
                a[r] -= (a[l] - 1);
                a[l] = 0;
                l++;
            }
            else
            {
                if (k < a[r] * 2)
                {
                    k = 0;
                    break;
                }

                k -= a[r] * 2;
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
        }
        else
        {
            if (a[l] < a[r])
            {
                if (k < a[l] * 2)
                {
                    k = 0;
                    break;
                }

                k -= a[l] * 2;
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }
            else
            {
                if (k < a[r] * 2 - 1)
                {
                    k = 0;
                    break;
                }

                flag = false;
                k -= a[r] * 2 - 1;
                a[l] -= (a[r] - 1);
                a[r] = 0;
                r--;
            }
        }
    }

    if (l == r)
    {
        if (a[l] <= k)
            cout << n << '\n';
        else
            cout << n - 1 << '\n';
    }
    else
    {
        cout << n - (r - l + 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

2 7
5 2


7
5 2

3
3

*/