#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 1, r = n, min_a = 1, max_a = n;
    while (l <= r)
    {
        if (a[l] != min_a && a[l] != max_a && a[r] != min_a && a[r] != max_a)
        {
            cout << l << " " << r << '\n';
            return;
        }

        if (a[l] == min_a)
        {
            l++;
            min_a++;
        }
        if (a[l] == max_a)
        {
            l++;
            max_a--;
        }
        if (a[r] == min_a)
        {
            r--;
            min_a++;
        }
        if (a[r] == max_a)
        {
            r--;
            max_a--;
        }
    }

    cout << -1 << '\n';
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