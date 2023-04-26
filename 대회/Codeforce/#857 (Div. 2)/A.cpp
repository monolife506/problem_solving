#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    int cnt[2] = {};
    for (int i = 0; i < n; ++i)
    {
        int bi;
        cin >> bi;
        (bi > 0) ? cnt[0]++ : cnt[1]++;
    }

    for (int i = 1; i <= cnt[0]; ++i)
        cout << i << " ";
    for (int i = 1; i <= cnt[1]; ++i)
        cout << cnt[0] - i << " ";

    cout << '\n';

    for (int i = 1; i <= cnt[1]; ++i)
        cout << 1 << " " << 0 << " ";
    for (int i = 1; i <= cnt[0] - cnt[1]; ++i)
        cout << i << " ";

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