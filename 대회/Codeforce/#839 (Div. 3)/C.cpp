#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int k, n;
    cin >> k >> n;

    vector<int> a(k);

    a[0] = 1;

    int d = 1;
    for (int i = 1; i < k; ++i)
    {
        if (a[i - 1] + d + ((k - 1) - i) <= n)
            a[i] = a[i - 1] + d++;
        else
            a[i] = a[i - 1] + 1;
    }

    for (int i = 0; i < k; ++i)
        cout << a[i] << " ";

    cout << '\n';
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

5 1 ~ 9

1 2 3

*/