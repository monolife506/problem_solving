#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    cout << accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL) - *max_element(b.begin(), b.end()) << '\n';
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

2 6 7 3
3 6 0 5

2 + 9 + 13 + 3
*/