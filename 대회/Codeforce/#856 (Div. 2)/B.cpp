#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            a[i]++;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i + 1] % a[i] == 0)
            a[i + 1]++;
    }

    for (int i = 0; i < n; ++i)
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

2 9 4 3

*/