#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int num = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] % num != 0)
            num = gcd(num, a[i] % num);
    }

    cout << a[n - 1] / num << '\n';
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

6 18 40

2 4 6 40


*/