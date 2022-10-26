#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
            flag = true;
    }

    cout << (flag ? "YES" : "NO") << '\n';
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

k = 5
0 0 0 0 1 0 -> NO


*/