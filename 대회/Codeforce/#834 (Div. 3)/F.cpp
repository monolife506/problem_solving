#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, p;
    cin >> n >> p;

    vector<int> a(n + 1);
    set<int> nums;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        nums.insert(a[i]);
    }

    int l_max = -1;
    int r_max = -1;
    for (int i = a[n] - 1; i >= max(0, a[n] - 101); --i)
    {
        if (nums.find(i) == nums.end())
        {
            l_max = i;
            break;
        }
    }
    for (int i = p - 1; i >= max(0, p - 101); --i)
    {
        if (nums.find(i) == nums.end())
        {
            r_max = i;
            break;
        }
    }

    if (l_max == -1 && r_max == -1)
    {
        cout << 0 << '\n';
    }
    else if (l_max == -1)
    {
        cout << r_max - a[n] << '\n';
    }
    else
    {
        nums.insert(0);
        bool flag = true;
        for (int i = n - 1; i >= 0; --i)
        {
            if (flag)
            {
                ++a[i];
                flag = false;
            }
            if (a[i] == p)
            {
                a[i] = 0;
                flag = true;
            }

            if (i != 0 || a[i] != 0)
            {
                nums.insert(a[i]);
            }
        }

        l_max = 0;
        for (int i = a[n] - 1; i >= max(1, a[n] - 1001); --i)
        {
            if (nums.find(i) == nums.end())
            {
                l_max = i;
                break;
            }
        }

        cout << (p - a[n]) + l_max << '\n';
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


1
5 5
1 2 2 2 4

1 2 2 3 0

0

*/