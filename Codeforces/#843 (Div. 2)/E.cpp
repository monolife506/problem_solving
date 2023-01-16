#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1), psum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    cout << *max_element(psum.begin(), psum.end()) - *min_element(psum.begin(), psum.end()) << '\n';
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

1 1 1
0 2 0
0 1 0
0 0 0

1 -1 1
0 0 1
0 0 0

*/