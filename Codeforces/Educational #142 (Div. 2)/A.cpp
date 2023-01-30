#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> h(n);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        if (h[i] == 1)
            cnt++;
    }

    cout << (n - cnt) + (cnt / 2) + (cnt % 2) << '\n';
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